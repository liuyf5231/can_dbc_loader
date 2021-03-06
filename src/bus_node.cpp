// Copyright (c) 2019 AutonomouStuff, LLC
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include "bus_node.hpp"

#include <memory>

namespace AS
{
namespace CAN
{
namespace DbcLoader
{

BusNode::BusNode(std::string && node_name)
  : name_(node_name),
    comment_(nullptr)
{
}

BusNode::BusNode(const BusNode & other)
  : name_(other.name_)
{
  if (comment_) {
    comment_ = std::make_unique<std::string>(*(other.comment_));
  } else {
    comment_ = nullptr;
  }
}

BusNode & BusNode::operator=(const BusNode & other)
{
  return *this = BusNode(other);
}

std::string BusNode::getName() const
{
  return name_;
}

const std::string * BusNode::getComment() const
{
  return comment_.get();
}

}  // namespace DbcLoader
}  // namespace CAN
}  // namespace AS
