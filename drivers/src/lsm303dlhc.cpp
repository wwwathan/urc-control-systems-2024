#include <lsm303dlhc.hpp>

namespace sjsu::drivers {

lsm303dlhc::lsm303dlhc(hal::v5::strong_ptr<hal::i2c> p_i2c)
  : m_i2c(p_i2c)
{
  start();
}

void lsm303dlhc::start()
{
  std::array<hal::byte, 2> start_address_a = { wake_up_accelerometer_register,
                                               wake_up_accelerometer_write };
  std::array<hal::byte, 2> start_address_m = { wake_up_magnetometer_register,
                                               wake_up_magnetometer_write };
  hal::write(*m_i2c,
             addresses::accelerometer_address,
             start_address_a,
             hal::never_timeout()),
    hal::write(*m_i2c,
               addresses::magnetometer_address,
               start_address_m,
               hal::never_timeout());
}

lsm303dlhc::lsm303dlhc_read_acceleration_data lsm303dlhc::read_accel_data(){
    std::array<hal::byte, 2> accel_x_address = {
        
    }
    std::array<hal::byte, 2> accel_y_address = {

    }
    std::array<hal::byte, 2> accel_z_address = {

    } 
    hal::write(*m_i2c, addresses::accelerometer_address, )
    hal::read(*m_i2c, 
}

lsm303dlhc::lsm303dlhc_read_magnetometer_data lsm303dlhc::read_mag_data()
{
  std::array<hal::byte, 1> read_address = { read_mag };
  std::array<hal::byte, 6> buffer;

  hal::write(*m_i2c,
             addresses::magnetometer_address,
             read_address,
             hal::never_timeout());
  hal::read(*m_i2c, addresses::magnetometer_address, buffer);

  lsm303dlhc::lsm303dlhc_read_magnetometer_data ra;
  ra.x_mag = buffer[0] << 8 | buffer[1];
  ra.z_mag = buffer[2] << 8 | buffer[3];
  ra.y_mag = buffer[4] << 8 | buffer[5];
}

}  // namespace sjsu::drivers
