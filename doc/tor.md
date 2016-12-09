TOR SUPPORT IN ECOcoin
======================

It is possible to run ecocoin as a Tor hidden service, and connect to such services.

The following directions assume you have a Tor proxy running on port 9050. Many distributions default to having a SOCKS proxy listening on port 9050, but others may not. In particular, the Tor Browser Bundle defaults to listening on a random port. See [Tor Project FAQ:TBBSocksPort](https://www.torproject.org/docs/faq.html.en#TBBSocksPort) for how to properly
configure Tor.


1. Run ECOcoin behind a Tor proxy
---------------------------------

The first step is running ecocoin behind a Tor proxy. This will already make all
outgoing connections be anonymized, but more is possible.

	-proxy=ip:port  Set the proxy server. If SOCKS5 is selected (default), this proxy
	                server will be used to try to reach .onion addresses as well.

	-onion=ip:port  Set the proxy server to use for tor hidden services. You do not
	                need to set this if it's the same as -proxy. You can use -noonion
	                to explicitly disable access to hidden service.

	-listen         When using -proxy, listening is disabled by default. If you want
	                to run a hidden service (see next section), you'll need to enable
	                it explicitly.

	-connect=X      When behind a Tor proxy, you can specify .onion addresses instead
	-addnode=X      of IP addresses or hostnames in these parameters. It requires
	-seednode=X     SOCKS5. In Tor mode, such addresses can also be exchanged with
	                other P2P nodes.

In a typical situation, this suffices to run behind a Tor proxy:

	./ecocoin -proxy=127.0.0.1:9050


2. Run a ECOcoin hidden server
------------------------------

If you configure your Tor system accordingly, it is possible to make your node also
reachable from the Tor network. Add these lines to your /etc/tor/torrc (or equivalent
config file):

	HiddenServiceDir /var/lib/tor/ecocoin-service/
	HiddenServicePort 7777 127.0.0.1:7777
	HiddenServicePort 17777 127.0.0.1:17777

The directory can be different of course, but (both) port numbers should be equal to
your ecocoind's P2P listen port (7777 by default, 17777 by default for testnet).

	-externalip=X   You can tell ecocoin about its publicly reachable address using
	                this option, and this can be a .onion address. Given the above
	                configuration, you can find your onion address in
	                /var/lib/tor/ecocoin-service/hostname. Onion addresses are given
	                preference for your node to advertize itself with, for connections
	                coming from unroutable addresses (such as 127.0.0.1, where the
	                Tor proxy typically runs).

	-listen         You'll need to enable listening for incoming connections, as this
	                is off by default behind a proxy.

	-discover       When -externalip is specified, no attempt is made to discover local
	                IPv4 or IPv6 addresses. If you want to run a dual stack, reachable
	                from both Tor and IPv4 (or IPv6), you'll need to either pass your
	                other addresses using -externalip, or explicitly enable -discover.
	                Note that both addresses of a dual-stack system may be easily
	                linkable using traffic analysis.

In a typical situation, where you're only reachable via Tor, this should suffice:

	./ecocoind -proxy=127.0.0.1:9050 -externalip=youraddress.onion -listen

(obviously, replace the Onion address with your own). If you don't care too much
about hiding your node, and want to be reachable on IPv4 as well, additionally
specify:

	./ecocoind ... -discover

and open port 7777 on your firewall.

If you only want to use Tor to reach onion addresses, but not use it as a proxy
for normal IPv4/IPv6 communication, use:

	./ecocoin -onion=127.0.0.1:9050 -externalip=youraddress.onion -discover

Known addresses of ecocoin nodes

seedhpmsmol5k9ik.onion
seed2r2xqyybp917.onion
seedcmj1wuvjgof1.onion
seedyhuwkt9e3wkf.onion
seedm02ufmulwsna.onion
seedg0c1wki3hqtr.onion
seedap130zc9xmvg.onion
seedlglfcltt94me.onion
seed0s06pf4ni625.onion
seed34gs180ixk0n.onion
seedgwmwu03miajx.onion
seedjgshvsj13vlt.onion
