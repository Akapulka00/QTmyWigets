# QTmyWigets
Этот репозиторий содержит простое приложение на основе Qt, которое демонстрирует два пользовательских виджета: анимированную кнопку и круглый прогресс-бар.

## Описание

Приложение разработано с использованием фреймворка Qt и содержит два настраиваемых виджета:

1. **Анимированная кнопка**: Пользовательская кнопка с анимацией перехода в красный цвет при нажатии, которая реагирует на клики.

2. **Круглый прогресс-бар**: Кастомизированный круговой индикатор прогресса для отображения процентного значения.

## Требования

Для запуска приложения требуется установленный фреймворк Qt.

## Запуск

1. Убедитесь, что у вас установлен Qt фреймворк.
2. Откройте проект в вашей среде разработки Qt.
3. Соберите и запустите проект.

## Использование виджетов

Данные виджеты наследуются от стандарных виджетов, что позволяет использавать все методы предоставляемые в рамках родительских классов. Для взаимодействия с прогесс баром использется сплит бокс соединеный с ним посредством сигнал слот.

## Лицензия
Этот проект лицензируется в соответствии с условиями MIT License.
