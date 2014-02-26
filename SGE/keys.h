#ifndef KEYS_H
#define KEYS_H
class status
{
      public:
             bool key_pressed_down;
             bool key_pressed_up;
             bool is_key_pressed;
             status();
};

class keys
{
      public:
	     bool key_down;
             status a;
             status b;
             status c;
             status d;
             status e;
             status f;
             status g;
             status h;
             status i;
             status j;
             status k;
             status l;
             status m;
             status n;
             status o;
             status p;
             status q;
             status r;
             status s;
             status t;
             status u;
             status v;
             status w;
             status x;
             status y;
             status z;
             
             status up;
             status down;
             status left;
             status right;
             
             status enter;
             
             status esc;
             status backspace;
             status tab;
             status del;
             status clear;
             status space;
             
             status one;
             status two;
             status three;
             status four;
             status five;
             status six;
             status seven;
             status eight;
             status nine;
             status zero;
             
             status rshift;
             status lshift;
             status rctrl;
             status lctrl;
             status lalt;
             status ralt;


             
      private:
};


status::status()
{
   key_pressed_down=false;
   key_pressed_up=false;
   is_key_pressed=false;
}
#endif
