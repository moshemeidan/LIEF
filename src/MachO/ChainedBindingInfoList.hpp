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
#ifndef LIEF_MACHO_CHAINED_BINDING_INFO_LIST_H
#define LIEF_MACHO_CHAINED_BINDING_INFO_LIST_H
#include <iostream>

#include "LIEF/visibility.h"
#include "LIEF/types.hpp"
#include "LIEF/MachO/ChainedBindingInfo.hpp"

#include "LIEF/MachO/enums.hpp"

namespace LIEF {
namespace MachO {
class BinaryParser;
class Builder;

class ChainedBindingInfoList : public ChainedBindingInfo {

  friend class BinaryParser;
  friend class Builder;

  public:
  ChainedBindingInfoList() = delete;
  explicit ChainedBindingInfoList(DYLD_CHAINED_FORMAT fmt, bool is_weak);

  ChainedBindingInfoList& operator=(ChainedBindingInfoList other) = delete;
  ChainedBindingInfoList(const ChainedBindingInfoList& other) = delete;

  ChainedBindingInfoList(ChainedBindingInfoList&&);

  void swap(ChainedBindingInfoList& other);

  ~ChainedBindingInfoList() override;

  static bool classof(const BindingInfo& info);

  private:
  std::vector<ChainedBindingInfo*> elements_;
};

}
}
#endif
