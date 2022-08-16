
template <class T>
bool touch_ground( T obj ) {

    if ( obj.getPosition().y + obj.getSize().y >= ground )
        return true;

    return false;

}

double original_velocity = -20;
double begin_velocity = original_velocity;
double current_velocity = original_velocity;
const double acceleration = 1;
const double flick_effect = 0.9;

enum { keep_jump, re_jump, stop_jump };

template <class U>
int jump( U &obj, double jump_velocity = current_velocity ) {

    obj.move(0.f, jump_velocity);

    if ( touch_ground(obj) ) {
        if ( begin_velocity > -1 ) {
            obj.setPosition( obj.getPosition().x, ground - obj.getSize().y );

            return stop_jump;

        }
        return re_jump;
    }


    current_velocity = jump_velocity + acceleration;

    return keep_jump;
    


}
