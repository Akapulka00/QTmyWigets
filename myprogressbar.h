#ifndef MYPROGRESSBAR_H
#define MYPROGRESSBAR_H

#include <QWidget>
#include <QProgressBar>
#include <QObject>
#include <QPaintEvent>
#include <QPainter>
#include <QPen>
#include <QDebug>
#include <QMouseEvent>
#include <QTimeLine>



class MyProgressbar : public QProgressBar
{
   Q_OBJECT
   private:
   int m_persent;
   public:
   MyProgressbar(QWidget* parent = nullptr) : QProgressBar(parent), m_persent(0){

   }
   void setPersent(int persent) // Метод для установки значения m_persent
   {
      m_persent = persent;
      update(); // Перерисовываем виджет после обновления значения
   }
     protected:
   void paintEvent(QPaintEvent *event)//отвечает за отрисовку содержимого виджета при необходимости обновления."
   {
      QPainter p(this);
      p.setRenderHint(QPainter::Antialiasing);
      setPersent(value());//устанавливаем значение процента
     int m_rotateAngle = 360 * m_persent / 100;//определяеим угол
      int side = qMin(width(), height());//определяем размер
      QRectF outRect(0, 0, side, side);//внутренний круг
      QRectF inRect(20, 20, side-40, side-40);//внешний круг
      QString valueStr = QString("%1%").arg(QString::number(m_persent));
      p.setPen(Qt::NoPen);
      p.setBrush(QBrush(QColor(255, 20, 60)));
      p.drawEllipse(outRect);// накладываем красный круг
      p.setBrush(QBrush(QColor(60, 179, 113)));
      p.drawPie(outRect, (90-m_rotateAngle)*16, m_rotateAngle*16);// накладываем зеленый кусочек)
      p.setBrush(palette().window().color());
      p.drawEllipse(inRect);
      QFont f = QFont("Microsoft YaHei", 15, QFont::Bold);
      p.setFont(f);
      p.setFont(f);
      p.setPen(QColor("#555555"));
      p.drawText(inRect, Qt::AlignCenter, valueStr);
   }
};

#endif // MYPROGRESSBAR_H
