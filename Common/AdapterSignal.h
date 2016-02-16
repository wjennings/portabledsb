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

#include "Common/AdapterObject.h"
#include "Common/AdapterNamedValue.h"

#include <string>
#include <vector>

namespace adapter
{
  class Interface;
  
  class Signal : public adapter::Object
  {
    friend class Interface;

  public:
    typedef std::vector<Signal> Vector;

    Signal(std::string const& name);

    std::string const& GetInterface() const
      { return m_interface; }

    NamedValue::Vector const& GetParameters() const
      { return m_params; }

    void AddParameter(NamedValue const& value)
      { m_params.push_back(value); }

    void ClearParameters()
      { m_params.clear(); }

  private:
    void SetInterfaceName(std::string const& name)
      { m_interface = name; }

  private:
    std::string         m_interface;
    NamedValue::Vector  m_params;
  };

  Signal MakeAdapterSignal(std::string const& name,
    NamedValue::Vector const& params = NamedValue::Vector());
}
