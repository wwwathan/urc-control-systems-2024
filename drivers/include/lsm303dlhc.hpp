#pragma once
#include <libhal-util/i2c.hpp>
#include <libhal/pointers.hpp>
#include <libhal/units.hpp>

namespace sjsu::drivers {

/**
 * @brief 3 direction accelerometer and magnetometer
 */

class lsm303dlhc
{

private:
  hal::v5::strong_ptr<hal::i2c> m_i2c;

  enum addresses
  {
    accelerometer_address = 0x19,
    wake_up_acceloremeter_register = 0x20,
    wake_up_accelerometer_write = 0x57,
    get_x_accel_address_lo = 0x28,
    get_x_accel_address_hi = 0x29,
    get_y_accel_address_lo = 0x2A,
    get_y_accel_address_hi = 0x2B,
    get_z_accel_address_lo = 0x2C,
    get_z_accel_address_hi = 0x2D,

    magnetometer_address = 0x1E,
    wake_up_magnetometer_register = 0x02,
    wake_up_magnetometer_write = 0x00,
    get_x_mag_address_lo = 0x03,
    get_x_mag_address_hi = 0x04,
    get_y_mag_address_lo = 0x05,
    get_y_mag_address_hi = 0x06,
    get_z_mag_address_lo = 0x07,
    get_z_mag_address_hi = 0x08
  };

public:
  struct lsm303dlhc_read_acceleration_data
  {
    float x_accel;
    float y_accel;
    float z_accel;
  };

  struct lsm303dlhc_read_magnetometer_data
  {
    float x_mag;
    float y_mag;
    float z_mag;
  };

  lsm303dlhc(hal::v5::strong_ptr<hal::i2c> p_i2c);
  void start();
  lsm303dlhc_read_acceleration_data read_accel_data();
  lsm303dlhc_read_magnetometer_data read_mag_data();
  void stop();
};

}  // namespace sjsu::drivers
