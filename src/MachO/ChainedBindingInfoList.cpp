/* Copyright 2017 - 2022 R. Thomas
 * Copyright 2017 - 2022 Quarkslab
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <numeric>
#include <iomanip>

#include "logging.hpp"
#include "LIEF/MachO/hash.hpp"
#include "ChainedBindingInfoList.hpp"
#include "MachO/ChainedFixup.hpp"

namespace LIEF {
namespace MachO {

ChainedBindingInfoList::ChainedBindingInfoList(ChainedBindingInfoList&&) = default;
ChainedBindingInfoList::~ChainedBindingInfoList() = default;

ChainedBindingInfoList::ChainedBindingInfoList(DYLD_CHAINED_FORMAT fmt, bool is_weak) :
  ChainedBindingInfo(fmt, is_weak)
{}

void ChainedBindingInfoList::swap(ChainedBindingInfoList& other) {
  ChainedBindingInfo::swap(other);
  std::swap(elements_, other.elements_);
}

bool ChainedBindingInfoList::classof(const BindingInfo& info) {
  return info.type() == BindingInfo::TYPES::CHAINED_LIST;
}

}
}
