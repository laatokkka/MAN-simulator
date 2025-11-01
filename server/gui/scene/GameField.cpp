#include "GameField.h"

#include <QShortcut>
#include <QMenu>
#include <QGraphicsItem>
#include <QDialog>
#include <QLineEdit>
#include <QSpinBox> 
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QComboBox>
#include <QPushButton>

GameField::GameField(QWidget* parent) {
    scene_ = new QGraphicsScene(this);
    setScene(scene_);

    setRenderHint(QPainter::Antialiasing);
    setDragMode(QGraphicsView::NoDrag);
    
    // TODO добавить приближение / отдаление
    //setDragMode(QGraphicsView::ScrollHandDrag);

    setSceneRect(0, 0, 350, 500);
    create_field();
}

void GameField::create_field() {
    scene_->clear();

    QColor BORDER_COLOR = QColor(191, 154, 85);
    QColor BACKGROUND_COLOR_DARK = QColor(20, 20, 20);
    QColor BACKGROUND_COLOR_LIGHT = QColor(26, 26, 26);

    // Задний фон
    double stripe_width = 30; // qt round it
    double offset = 20;
    QColor filling_color;

    scene_->addRect(0, 0, 340, 20, QPen(BACKGROUND_COLOR_LIGHT), QBrush(BACKGROUND_COLOR_LIGHT));

    int border = offset;
    for (int i = 0; i < 15; i++) {
        if (i % 2 == 0) filling_color = BACKGROUND_COLOR_DARK;
        else filling_color = BACKGROUND_COLOR_LIGHT;

        scene_->addRect(0, border, 340, stripe_width, QPen(filling_color), QBrush(filling_color));
        border += stripe_width;
    }

    scene_->addRect(0, border, 340, 20, QPen(BACKGROUND_COLOR_LIGHT), QBrush(BACKGROUND_COLOR_LIGHT));

    // TODO границы сцены
    // scene_->addRect(0, 0, 350, 500, QPen(/* Другой цвет */, 1));

    // Границы поля
    scene_->addRect(20, 20, 300, 450, QPen(BORDER_COLOR, 1));
    
    // Ворота
    scene_->addRect(120, 0, 100, 20, QPen(BORDER_COLOR, 1));
    scene_->addRect(120, 470, 100, 20, QPen(BORDER_COLOR, 1));
}

void GameField::mousePressEvent(QMouseEvent* event) {
    QPointF mouse_position = mapToScene(event->pos());

    if (event->button() == Qt::LeftButton) {
        // TODO перемещение объекта
        QGraphicsView::mousePressEvent(event);

    } else if (event->button() == Qt::RightButton) {
        QMenu sub_menu;
        sub_menu.addAction("Add Player", [this, mouse_position] {

        });

        sub_menu.addAction("Remove Player", [this, mouse_position] {
            // ?
        });

        sub_menu.addAction("Edit Player", [this, mouse_position] {
            // TODO повторное открытие окна при нажатии на игрока
        });

        sub_menu.exec(event->globalPosition().toPoint());
    }
}