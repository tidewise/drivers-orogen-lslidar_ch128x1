/* Generated from orogen/lib/orogen/templates/tasks/Task.cpp */

#include "Task.hpp"
#include <iodrivers_base/ConfigureGuard.hpp>
#include <lslidar_ch128x1/Driver.hpp>

using namespace lslidar_ch128x1;
using namespace iodrivers_base;

lslidar_ch128x1::Task::Task(std::string const& name)
    : TaskBase(name)
{
}

lslidar_ch128x1::Task::~Task()
{
}

bool lslidar_ch128x1::Task::configureHook()
{
    iodrivers_base::ConfigureGuard guard(this);
    lslidar_ch128x1::Driver* driver = new lslidar_ch128x1::Driver();
    if (!_io_port.get().empty())
        driver->openURI(_io_port.get());
    setDriver(driver);
    if (!TaskBase::configureHook())
        return false;
    guard.commit();
    return true;
}

bool lslidar_ch128x1::Task::startHook()
{
    if (!TaskBase::startHook())
        return false;
    return true;
}

void lslidar_ch128x1::Task::updateHook()
{
    TaskBase::updateHook();
}

void lslidar_ch128x1::Task::errorHook()
{
    TaskBase::errorHook();
}

void lslidar_ch128x1::Task::stopHook()
{
    TaskBase::stopHook();
}

void lslidar_ch128x1::Task::cleanupHook()
{
    TaskBase::cleanupHook();
}

void lslidar_ch128x1::Task::processIO()
{
    Driver* driver = static_cast<lslidar_ch128x1::Driver*>(mDriver);
    std::optional<base::samples::Pointcloud> point_cloud = driver->read();
    if (point_cloud.has_value()) {
        _point_cloud.write(*point_cloud);
    }
}
