# pragma once


class Ball {
    private:
        // QPointF self_position_;
        // QPointF self_direction_; // REMOVE ?

        float self_speed_; // REMOVE ?

    public:
        explicit Ball();
        void update();
};