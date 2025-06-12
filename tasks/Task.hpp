/* Generated from orogen/lib/orogen/templates/tasks/Task.hpp */

#ifndef LSLIDAR_CH128X1_TASK_TASK_HPP
#define LSLIDAR_CH128X1_TASK_TASK_HPP

#include "lslidar_ch128x1/TaskBase.hpp"

namespace lslidar_ch128x1 {
    class Task : public TaskBase {
        friend class TaskBase;

    protected:
    public:
        Task(std::string const& name = "lslidar_ch128x1::Task");
        ~Task();
        bool configureHook();
        bool startHook();
        void updateHook();
        void errorHook();
        void stopHook();
        void cleanupHook();
        void processIO();
    };
}

#endif
