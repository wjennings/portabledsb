//
// Copyright (c) 2016, Comcast Cable Communications Management, LLC
//
// Permission to use, copy, modify, and/or distribute this software for any purpose with or
// without fee is hereby granted, provided that the above copyright notice and this
// permission notice appear in all copies.
//
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO
// THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT
// SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR
// ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION
// OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE
// USE OR PERFORMANCE OF THIS SOFTWARE.
//
#pragma once

#include "Common/AdapterItemInformation.h"
#include "Common/AdapterInterface.h"

namespace adapter
{
  class Device
  {
  public:
    typedef std::vector<Device> Vector;
    typedef std::vector< std::shared_ptr<Device> > ChildList;

    ItemInformation const& GetInfo() const
      { return m_info; }

    void SetBasicInfo(ItemInformation const& info)
      { m_info = info; }

    // interfaces
    void AddInterface(Interface const& interface)
      { m_interfaces.push_back(interface); }

    void ClearInterfaces()
      { m_interfaces.clear(); }

    inline Interface::Vector const& GetInterfaces() const
      { return m_interfaces; }

    // children
    void AddChild(std::shared_ptr<Device> const& dev);

    void ClearChildren()
      { m_children.clear(); }

    inline ChildList const& GetChildren() const
      { return m_children; }

  private:
    ItemInformation         m_info;
    Interface::Vector       m_interfaces;
    ChildList               m_children;
  };
}
