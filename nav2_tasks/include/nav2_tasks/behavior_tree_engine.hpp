// Copyright (c) 2018 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef NAV2_TASKS__BEHAVIOR_TREE_ENGINE_HPP_
#define NAV2_TASKS__BEHAVIOR_TREE_ENGINE_HPP_

#include <string>
#include "rclcpp/rclcpp.hpp"
#include "behavior_tree_core/behavior_tree.h"
#include "behavior_tree_core/bt_factory.h"
#include "behavior_tree_core/xml_parsing.h"
#include "nav2_tasks/task_status.hpp"

namespace nav2_tasks
{

class BehaviorTreeEngine
{
public:
  explicit BehaviorTreeEngine(rclcpp::Node::SharedPtr node);
  BehaviorTreeEngine() = delete;

  TaskStatus run(
    const std::string & behavior_tree_xml,
    std::function<bool()> cancelRequested,
    std::chrono::milliseconds loopTimeout = std::chrono::milliseconds(100));

protected:
  virtual void registerCustomActions() {}

  // The ROS node to use for any task clients
  rclcpp::Node::SharedPtr node_;

  // A factory that will be used to dynamically construct the behavior tree
  BT::BehaviorTreeFactory factory_;
};

}  // namespace nav2_tasks

#endif  // NAV2_TASKS__BEHAVIOR_TREE_ENGINE_HPP_
