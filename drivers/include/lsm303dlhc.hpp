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
    ctrl_reg1_a = 0x20,
    accelerometer_config = 0x57,
    read_accel = 0xA8,
    /**get_x_accel_address_hi = 0x29,
    get_y_accel_address_lo = 0x2A,
    get_y_accel_address_hi = 0x2B,
    get_z_accel_address_lo = 0x2C,
    get_z_accel_address_hi = 0x2D,**/

    magnetometer_address = 0x1E,
    mr_reg_m = 0x02,
    magnetometer_config = 0x00,
    read_mag = 0x03
    // get_x_mag_address_hi = 0x04,
    // get_y_mag_address_lo = 0x05,
    // get_y_mag_address_hi = 0x06,
    // get_z_mag_address_lo = 0x07,
    // get_z_mag_address_hi = 0x08
  };

public:
  struct lsm303dlhc_read_acceleration_data
  {
    int16_t x_accel;
    int16_t y_accel;
    int16_t z_accel;
  };

  struct lsm303dlhc_read_magnetometer_data
  {
    int16_t x_mag;
    int16_t y_mag;
    int16_t z_mag;
  };

  lsm303dlhc(hal::v5::strong_ptr<hal::i2c> p_i2c);
  void start();
  lsm303dlhc_read_acceleration_data read_accel_data();
  lsm303dlhc_read_magnetometer_data read_mag_data();
  void stop();
};

}  // namespace sjsu::drivers
