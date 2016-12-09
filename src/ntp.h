// Copyright (c) 2016 The ECOcoin Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or https://opensource.org/licenses/mit-license.php
#ifndef ecocoin_NTP_H
#define ecocoin_NTP_H

// Get time from random server and return server address.
int64_t NtpGetTime(CNetAddr& ip);

// Get time from provided server.
int64_t NtpGetTime(const std::string &strHostName);

extern std::string strTrustedUpstream;

// NTP time samples thread.
void ThreadNtpSamples(void* parg);

// NTP offset
int64_t GetNtpOffset();

#endif // ecocoin_NTP_H
