#include <libhal/timeout.hpp>
#include <lsm303dlhc.hpp>

namespace sjsu::drivers {

lsm303dlhc::lsm303dlhc(hal::v5::strong_ptr<hal::i2c> p_i2c)
  : m_i2c(std::move(p_i2c))
{
  start();
}

void lsm303dlhc::start()
{
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
  ra.x_accel = (buffer[1] << 8 | buffer[0]);
  ra.y_accel = (buffer[3] << 8 | buffer[2]);
  ra.z_accel = (buffer[5] << 8 | buffer[4]);

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
  ra.x_mag = buffer[0] << 8 | buffer[1];
  ra.z_mag = buffer[2] << 8 | buffer[3];
  ra.y_mag = buffer[4] << 8 | buffer[5];

  return ra;
}

}  // namespace sjsu::drivers
