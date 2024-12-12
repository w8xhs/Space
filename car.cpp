#include "Car.h"
#include <QPainter>

Car::Car() : xPos(0), moving(false) {
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [this]() {
        if (moving) {
            xPos += 5; // Увеличиваем позицию по оси X
            if (xPos > 800) xPos = 0; // Сброс позиции, если она выходит за пределы
            update(); // Перерисовка
        }
    });
}

void Car::setScene(QGraphicsScene *scene) {
    this->scene = scene;
    scene->addItem(this); // Добавление машины на сцену
}

void Car::start() {
    moving = true; // Устанавливаем флаг движения
    timer->start(100); // Запускаем таймер с интервалом 100 мс
}

void Car::stop() {
    moving = false; // Останавливаем движение
    timer->stop(); // Останавливаем таймер
}

QRectF Car::boundingRect() const {
    return QRectF(0, 0, 50, 30); // Ограничивающий прямоугольник для машины
}

void Car::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(Qt::blue); // Цвет машины
    painter->drawRect(0, 0, 50, 30); // Рисуем прямоугольник как машину
}
