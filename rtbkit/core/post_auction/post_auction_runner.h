/** post_auction_runner.h                                                -*- C++ -*-
    JS Bejeau, 14 February 2014
    Copyright (c) 2012 Datacratic.  All rights reserved.

    Program to run the post_auction_loop.
*/

#pragma once


#include <boost/program_options/options_description.hpp>
#include "rtbkit/core/post_auction/post_auction_service.h"
#include "rtbkit/core/banker/slave_banker.h"
#include "soa/service/service_utils.h"

namespace RTBKIT {


/*****************************************************************************/
/* ROUTER RUNNER                                                             */
/*****************************************************************************/

struct PostAuctionRunner {

    PostAuctionRunner();     

    ServiceProxyArguments serviceArgs;
    SlaveBankerArguments bankerArgs;

    size_t shard;
    float auctionTimeout;
    float winTimeout;
    std::string bidderConfigurationFile;

    int winLossPipeTimeout;
    int campaignEventPipeTimeout;
    bool analyticsOn;
    int analyticsConnections;

    std::string forwardAuctionsUri;

    void doOptions(int argc, char ** argv,
                   const boost::program_options::options_description & opts
                   = boost::program_options::options_description());

    std::shared_ptr<ServiceProxies> proxies;
    std::shared_ptr<SlaveBanker> banker;
    std::shared_ptr<PostAuctionService> postAuctionLoop;

    void init();

    void start();

    void shutdown();

    static Logging::Category print;
    static Logging::Category trace;
    static Logging::Category error;

};

} // namespace RTBKIT

