%module packet
%{
#include <haka/packet_module.h>
#include "../app.h"

void lua_pushppacket(lua_State *L, struct packet *pkt)
{
    SWIG_NewPointerObj(L, pkt, SWIGTYPE_p_packet, 0);
}
%}

%rename(ACCEPT) FILTER_ACCEPT;
%rename(DROP) FILTER_DROP;

enum filter_result { FILTER_ACCEPT, FILTER_DROP };

%nodefaultctor;

struct packet {
    %extend {
        %immutable;
        size_t length;
    }
};

%{
size_t packet_length_get(struct packet *pkt) {
   return get_packet_module()->get_length(pkt);
}
%}

