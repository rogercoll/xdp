#include <linux/bpf.h>
#include <linux/if_ether.h>
//#include <netinet/in.h>
#define SEC(NAME) __attribute__((section(NAME), used))
SEC("prog")

static inline int rule_1(void *data, void *data_end) {
	struct ethhdr *eth_hdr;
	struct iphdr  *ip_hdr;
	struct tcphdr *tcp_hdr;
	//u8	      *tcp_opts;

	eth_hdr = (struct ethhdr *)data;
	if (eth_hdr + 1 > (struct ethhdr *)data_end)
		return XDP_ABORTED;
	else if (eth_hdr->h_proto == htons(ETH_P_IP))
		return XDP_PASS;	
}

int  xdp_prog_filter(struct xdp_md *ctx)
{
	void *data = (void *)(long)ctx->data;
	void *data_end = (void *)(long)ctx->data_end;

	int result;
	result = rule_1(data, data_end);
	if (result == XDP_PASS) {
		return result;
	}

        return XDP_DROP;
}

