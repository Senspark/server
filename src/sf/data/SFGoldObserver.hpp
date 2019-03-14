//
//  SFGoldObserver.hpp
//  gold-miner-vegas
//
//  Created by eps on 3/2/18.
//

#ifndef SF_GOLD_OBSERVER_HPP
#define SF_GOLD_OBSERVER_HPP

#include "SFForward.hpp"

#include <boost/shared_ptr.hpp>

/*
namespace sf {
class GoldObserver {
private:
    using Self = GoldObserver;

public:
    using Callback = std::function<void(int amount)>;

    explicit GoldObserver(const Callback& callback);
    
    ~GoldObserver();

protected:
    void onUserInfoRequest(
        const boost::shared_ptr<Sfs2X::Entities::Data::ISFSObject>& object);
    void onSetGoldRequest(
        const boost::shared_ptr<Sfs2X::Entities::Data::ISFSObject>& object);

private:
    Callback callback_;

    std::shared_ptr<ExtensionResponseListener> extensionListener_;
};
} // namespace sf
 */

#endif /* SF_GOLD_OBSERVER_HPP */
