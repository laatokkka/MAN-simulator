#pragma once
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>

class Field : public QGraphicsView {
    Q_OBJECT
    private:
        QGraphicsScene* scene_ = nullptr;

        void create_field();


        //void connect_ui();

    protected:
        // Обработка нажатий
        void mousePressEvent(QMouseEvent* event) override;

    public:
        explicit Field(QWidget* parent = nullptr);
};