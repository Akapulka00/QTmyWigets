#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QObject>
#include <QPaintEvent>
#include <QPainter>
#include <QPen>
#include <QDebug>
#include <QMouseEvent>
#include <QTimeLine>

#define WAY 1

class MyButton : public  QPushButton

{
   Q_OBJECT
   QTimeLine m_tl;
   public:
   MyButton(QWidget* parent = nullptr)
           :QPushButton(parent)
       {
          QFont font("Arial", 16, QFont::Bold);
          setFont(font);
          m_tl.setFrameRange(0,100);
          m_tl.setDuration(500);
          m_tl.setDirection(QTimeLine::Backward);
          m_tl.setEasingCurve(QEasingCurve::InQuad);
          connect(&m_tl, &QTimeLine::frameChanged,[this](){update();});
       }
   protected:

       int len_text;
       void paintEvent(QPaintEvent *event)//отвечает за отрисовку содержимого виджета при необходимости обновления."
       {
          QPainter p(this);//Создание обекьта P который будет использоваться для рисования на виджете."
          QRect _rect = rect();//Создается прямоугольник _rect, который представляет границы виджета.
          {
             p.save();
             QPen pen(Qt::black, 1,Qt::SolidLine,Qt::SquareCap);//Создается объект QPen pen(Qt::green, _rect.height()/3, Qt::SolidLine, Qt::RoundCap), который будет использоваться для рисования линии.
             p.setPen(pen);//Устанавливается созданный ранее объект pen как текущий перо для QPainter p.
             p.drawRect(0, 0, _rect.width()-1, _rect.height()-1);//С помощью метода p.drawLine() рисуется горизонтальная линия, начиная от (_rect.height()/2, _rect.height()/2) и заканчивая (_rect.width()-rect().height()/2, _rect.height()/2).
             p.restore();//После отрисовки линии состояние рисования восстанавливается из ранее сохраненного состояния
          }
          p.setBrush(Qt::red);//Устанавливается зеленая кисть для заливки фигур, которые будут рисоваться.
          QPen pen(Qt::red, 1,Qt::SolidLine,Qt::RoundCap);//оздается объект QPen pen(Qt::green, _rect.height()/1.5, Qt::SolidLine, Qt::RoundCap), который будет использоваться для рисования точки."
          //"Устанавливается созданный ранее объект pen как текущий перо для QPainter p.
          p.setPen(pen);

          auto tlpos = m_tl.currentValue();//Вычисляется текущая позиция точки по оси x с использованием значения текущего времени, хранимого в переменной m_tl
          if(tlpos!=0){
          p.drawRect(0, 0,_rect.width()*tlpos-1, _rect.height()-1);
          }
          if(tlpos<0.5){
          QPen textPen(Qt::black); // Устанавливаем черный цвет для пера
          p.setPen(textPen);
          p.drawText(_rect.width()/2-(text().length()*5), _rect.height()/1.6, text());
          }else{
          QPen textPen(Qt::white); // Устанавливаем черный цвет для пера
          p.setPen(textPen);
          p.drawText(_rect.width()/2-(text().length()*5), _rect.height()/1.6, text());
          }
       }
       void mousePressEvent(QMouseEvent *event)
       {
          if(event->buttons() & Qt::LeftButton)
          {
             setChecked(!isChecked());
             auto d = m_tl.direction();
             d = (d == QTimeLine::Forward) ? QTimeLine::Backward : QTimeLine::Forward;
             m_tl.setDirection(d);
             m_tl.start();
             update();
          }
       }
};

#endif // MYBUTTON_H
