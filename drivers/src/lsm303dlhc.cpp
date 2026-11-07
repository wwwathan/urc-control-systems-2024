#include <libhal/timeout.hpp>
#include <lsm303dlhc.hpp>

namespace sjsu::drivers {

lsm303dlhc::lsm303dlhc(hal::v5::strong_ptr<hal::i2c> p_i2c)
  : m_i2c(p_i2c)
{
  start();
}

void lsm303dlhc::start()
{
<<<<<<< HEAD
  std::array<hal::byte, 2> start_address_a = {
    lsm303dlhc::ctrl_reg1_a, lsm303dlhc::accelerometer_config
  };
  std::array<hal::byte, 2> start_address_m = { mr_reg_m, magnetometer_config };
  hal::write(*m_i2c,
             addresses::accelerometer_address,
             start_address_a,
             hal::never_timeout()),
    hal::write(*m_i2c,
               addresses::magnetometer_address,
               start_address_m,
               hal::never_timeout());
=======

  // power on accelorometer and magnetometer
  std::array<hal::byte, 2> start_address_a = {
    lsm303dlhc::ctrl_reg1_a, lsm303dlhc::accelerometer_config
  };

  std::array<hal::byte, 2> start_address_m = { mr_reg_m, magnetometer_config };

  std::array<hal::byte, 2> accel_sensitivity = {
    lsm303dlhc::ctrl_reg4_a, lsm303dlhc::accelerometer_sensitivity_config
  };

  std::array<hal::byte, 2> mag_sensitivity = {
    lsm303dlhc::crb_reg_m, lsm303dlhc::magnetometer_sensitivity_config
  };

  hal::write(*m_i2c,
             addresses::magnetometer_address,
             mag_sensitivity,
             hal::never_timeout());

  hal::write(*m_i2c,
             addresses::accelerometer_address,
             start_address_a,
             hal::never_timeout());
  hal::write(*m_i2c,
             addresses::magnetometer_address,
             start_address_m,
             hal::never_timeout());
  // configure sensitivity (to convert raw data to scaled data)
  // accelerometer change ctrl_reg4_a - configure fs bit?

  hal::write(*m_i2c,
             addresses::accelerometer_address,
             accel_sensitivity,
             hal::never_timeout());
  // can use 001 for GN[2:0] for +-1.3 gauss
>>>>>>> kat-lsm303dlhc
}

lsm303dlhc::lsm303dlhc_read_acceleration_data lsm303dlhc::read_accel_data()
{
  // std::array<hal::byte, 2> accel_x_address = {
  //  this is the register address + data
  // get_x_accel_address_hi,
  // get_x_accel_address_lo
  //};

  std::array<hal::byte, 1> read_address = { read_accel };
  std::array<hal::byte, 6> buffer;
  hal::write(*m_i2c,
             addresses::accelerometer_address,
             read_address,
             hal::never_timeout());
  hal::read(
    *m_i2c, addresses::accelerometer_address, buffer, hal::never_timeout());

  lsm303dlhc::lsm303dlhc_read_acceleration_data ra;
<<<<<<< HEAD
  ra.x_accel = (buffer[1] << 8 | buffer[0]);
  ra.y_accel = (buffer[3] << 8 | buffer[2]);
  ra.z_accel = (buffer[5] << 8 | buffer[4]);
=======
  int16_t raw_xa = (buffer[1] << 8 | buffer[0]);
  int16_t raw_ya = (buffer[3] << 8 | buffer[2]);
  int16_t raw_za = (buffer[5] << 8 | buffer[4]);

  raw_xa >>= 4;
  raw_ya >>= 4;
  raw_za >>= 4;

  ra.x_accel = raw_xa / 1000.0f;
  ra.y_accel = raw_ya / 1000.0f;
  ra.z_accel = raw_za / 1000.0f;
>>>>>>> kat-lsm303dlhc

  return ra;
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
<<<<<<< HEAD
  ra.x_mag = buffer[0] << 8 | buffer[1];
  ra.z_mag = buffer[2] << 8 | buffer[3];
  ra.y_mag = buffer[4] << 8 | buffer[5];
=======
  int16_t raw_xm = buffer[0] << 8 | buffer[1];
  int16_t raw_zm = buffer[2] << 8 | buffer[3];
  int16_t raw_ym = buffer[4] << 8 | buffer[5];

  ra.x_mag = raw_xm / 1100.0f;
  ra.y_mag = raw_ym / 1100.0f;
  ra.z_mag = raw_zm / 980.0f;
>>>>>>> kat-lsm303dlhc

  return ra;
}

}  // namespace sjsu::drivers
