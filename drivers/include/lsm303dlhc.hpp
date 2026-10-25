#include <libhal/pointers.hpp>
#include <libhal/i2c.hpp>

namespace sjsu::drivers {

    
    /**
    * @brief 3 direction accelerometer and magnetometer
    */

    class lsm303dlhc {

        private:
        hal::v5::strong_ptr<hal::i2c> m_i2c;
        
        public:

            float read_acceleration();

            

    };

}
