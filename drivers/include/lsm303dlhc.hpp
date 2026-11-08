#pragma once
#include <libhal-util/i2c.hpp>
#include <libhal/pointers.hpp>
#include <libhal/units.hpp>

namespace sjsu::drivers {

/**
 * @brief Driver for the LSM303DLHC 3-axis accelerometer and magnetometer.
 *
 * Initializes both sensors over I2C and provides scaled acceleration
 * and magnetic-field measurements for the x, y, and z axes.
 */

class lsm303dlhc
{

private:
  hal::v5::strong_ptr<hal::i2c> m_i2c;

  enum addresses
  {
    accelerometer_address = 0x19,
    ctrl_reg1_a = 0x20,
    accelerometer_config = 0x57,
    read_accel = 0xA8,
    ctrl_reg4_a = 0x23,
    accelerometer_sensitivity_config = 0x08,

    magnetometer_address = 0x1E,
    mr_reg_m = 0x02,
    magnetometer_config = 0x00,
    read_mag = 0x03,
    crb_reg_m = 0x01,
    magnetometer_sensitivity_config = 0x20
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

  /**
   * @brief Reads scaled acceleration in three directions
   *
   * @return data for the x, y, and z axes as float
   */
  lsm303dlhc_read_acceleration_data read_accel_data();
  /**
   * @brief Reads scaled magnetic-field in three directions
   * 
   * @return data for the x, y, and z axes as float
   */
  lsm303dlhc_read_magnetometer_data read_mag_data();
  void stop();
};

}  // namespace sjsu::drivers
