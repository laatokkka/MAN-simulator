#pragma once
#include "PlayerDialog.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>

class GameField : public QGraphicsView {
    Q_OBJECT
    private:
        QGraphicsScene *scene_ = nullptr;
        PlayerDialog *dialog_ = nullptr;

        void create_field();

    protected:
        void mousePressEvent(QMouseEvent *event) override;

    public:
        explicit GameField(QWidget *parent = nullptr);
};