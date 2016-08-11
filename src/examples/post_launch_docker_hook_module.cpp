// Licensed to the Apache Software Foundation (ASF) under one
// // or more contributor license agreements.  See the NOTICE file
// // distributed with this work for additional information
// // regarding copyright ownership.  The ASF licenses this file
// // to you under the Apache License, Version 2.0 (the
// // "License"); you may not use this file except in compliance
// // with the License.  You may obtain a copy of the License at
// //
// //     http://www.apache.org/licenses/LICENSE-2.0
// //
// // Unless required by applicable law or agreed to in writing, software
// // distributed under the License is distributed on an "AS IS" BASIS,
// // WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// // See the License for the specific language governing permissions and
// // limitations under the License.

#include <mesos/hook.hpp>
#include <mesos/mesos.hpp>
#include <mesos/module.hpp>

#include <mesos/module/hook.hpp>

#include <process/future.hpp>
#include <process/process.hpp>
#include <process/protobuf.hpp>

#include <stout/foreach.hpp>
#include <stout/os.hpp>
#include <stout/try.hpp>

#include "messages/messages.hpp"

using namespace mesos;

using std::map;
using std::string;

using process::Future;

class PostLaunchDockerHook : public Hook
{
public:
  virtual Result<Labels> masterLaunchTaskLabelDecorator(
      const TaskInfo& taskInfo,
      const FrameworkInfo& frameworkInfo,
      const SlaveInfo& slaveInfo)
  {
    LOG(INFO) << "Executing 'masterLaunchTaskLabelDecorator' hook";
    return None();
  }

  virtual Try<Nothing> masterSlaveLostHook(const SlaveInfo& slaveInfo)
  {
    LOG(INFO) << "Executing 'masterSlaveLostHook' in slave '"
              << slaveInfo.id() << "'";
    return Nothing();
  }


  // TODO(nnielsen): Split hook tests into multiple modules to avoid
  // interference.
  virtual Result<Labels> slaveRunTaskLabelDecorator(
      const TaskInfo& taskInfo,
      const ExecutorInfo& executorInfo,
      const FrameworkInfo& frameworkInfo,
      const SlaveInfo& slaveInfo)
  {
    LOG(INFO) << "Executing 'slaveRunTaskLabelDecorator' hook";

    return None();
  }


  // In this hook, we create a new environment variable "FOO" and set
  // it's value to "bar".
  virtual Result<Environment> slaveExecutorEnvironmentDecorator(
      const ExecutorInfo& executorInfo)
  {
    LOG(INFO) << "Executing 'slaveExecutorEnvironmentDecorator' hook";
    return None();
  }


  virtual Try<Nothing> slavePreLaunchDockerHook(
      const ContainerInfo& containerInfo,
      const CommandInfo& commandInfo,
      const Option<TaskInfo>& taskInfo,
      const ExecutorInfo& executorInfo,
      const string& name,
      const string& sandboxDirectory,
      const string& mappedDirectory,
      const Option<Resources>& resources,
      const Option<map<string, string>>& env)
  {
    LOG(INFO) << "Executing 'slavePreLaunchDockerHook'";
    return Nothing();
  }

  virtual Try<Nothing> slavePostLaunchDockerHook(
      const ContainerInfo& containerInfo,
      const CommandInfo& commandInfo,
      const Option<TaskInfo>& taskInfo,
      const ExecutorInfo& executorInfo,
      const string& name,
      const string& sandboxDirectory,
      const string& mappedDirectory,
      const Option<Resources>& resources,
      const Option<map<string, string>>& env)
  {
    LOG(INFO) << "Executing 'slavePostLaunchDockerHook'";
    return Nothing();
  }


  // This hook locates the file created by environment decorator hook
  // and deletes it.
  virtual Try<Nothing> slaveRemoveExecutorHook(
      const FrameworkInfo& frameworkInfo,
      const ExecutorInfo& executorInfo)
  {
    LOG(INFO) << "Executing 'slaveRemoveExecutorHook'";
    return Nothing();
  }


  virtual Result<TaskStatus> slaveTaskStatusDecorator(
      const FrameworkID& frameworkId,
      const TaskStatus& status)
  {
    LOG(INFO) << "Executing 'slaveTaskStatusDecorator' hook";
    return None();
  }


  virtual Result<Resources> slaveResourcesDecorator(
      const SlaveInfo& slaveInfo)
  {
    LOG(INFO) << "Executing 'slaveResourcesDecorator' hook";
    return None();
  }


  virtual Result<Attributes> slaveAttributesDecorator(
      const SlaveInfo& slaveInfo)
  {
    LOG(INFO) << "Executing 'slaveAttributesDecorator' hook";
    return None();
  }
};


static Hook* createHook(const Parameters& parameters)
{
  return new PostLaunchDockerHook();
}


// Declares a Hook module named 'org_apache_mesos_TestHook'.
mesos::modules::Module<Hook> org_apache_mesos_PostLaunchDockerHook(
    MESOS_MODULE_API_VERSION,
    MESOS_VERSION,
    "Linker Networks",
    "cliu@linkernetworks.com",
    "PostLaunchDockerHook",
    NULL,
    createHook);
