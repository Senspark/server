//
//  SFListener.hpp
//  climber
//
//  Created by Zinge on 12/15/17.
//
//

#ifndef SF_I_LISTENER_HPP
#define SF_I_LISTENER_HPP

#include <map>
#include <string>

#include "sf/Forward.hpp"

#include <boost/shared_ptr.hpp>

namespace sf {
class IListener {
public:
    using Parameter =
        boost::shared_ptr<std::map<std::string, boost::shared_ptr<void>>>;

    virtual ~IListener() = default;

    /// Gets the vent listener type.
    virtual const boost::shared_ptr<std::string>& getType() const = 0;

    virtual void onEvent(const Parameter& params) = 0;
};
} // namespace sf

#endif /* SENSPARK_SF_LISTENER_HPP */
