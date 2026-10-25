#include <lsm303dlhc.hpp>


namespace sjsu::drivers {

lsm303dlhc::lsm303dlhc(hal::v5::strong_ptr<hal::i2c> p_i2c) 
: m_i2c(p_i2c)
{
    start();
}

void lsm303dlhc::start() 
{
    std::array<hal::byte, 2> start_addres_a = {
        [0]=wake_up_acceleromter_register,
        [1]=wake_up_accelerometer_write
    };
    std::array<hal::byte, 2> start_addres_m = {
        [0]=wake_up_magnetometer_register,
        [1]=wake_up_magnetometer_write
    };
    hal::write(*m_i2c, addresses::accelerometer_address, start_address_a, hal::never_timeout()),
    hal::write(*m_i2c, addresses::magnetometer_address, start_address_m, hal::never_timeout());
}

lsm303dlhc::lsm303dlhc_read_data lsm303dlhc::read_accel_data(){
    std::array<hal::byte, 2> accel_x_address = {
        
    }
    std::array<hal::byte, 2> accel_y = {

    }
    std::array<hal::byte, 2> accel_z = {

    } 
    hal::write(*m_i2c, addresses::accelerometer_address, )
    hal::read(*m_i2c, 
}

}