

Peer to peer一点的思路

理论上来说，P2P不是普通的C/S模式， 每一个网络节点既是客户端，又都是服务器端，所以既可以发送又可以接收。这样的话，网络节点之间无需中心服务器即可通信，通信内容可以经由多个节点到达目的节点。目前IPV4由于物理地址耗尽，无法形成完全的点对点互联互通，形成了处于内网中的LOW ID和公网上的High ID，但IPV6体系成熟以后在未来可以做到。所以目前P2P可以写成IPV6和IPv4两个版本，IPV6相对来说比较简单，而IPV4版本比较复杂，要考虑的因素会更多，处理异常的代码也会更多。



p2p_client.c

// 接收基本单位内容并转发其他节点



-------------------------------------------------------
IPV4_p2p_server.c

```C
int main( int argc, char* argv[] )
{
    while( 1 ){
    
    get_requests();
    sent_m_to_clients();        //发送所有请求节点信息到每一个客户端
    collect_allclients_info();  //收集所有节点反馈信息
    spilt_content();            //拆分发送内容为基本单位
    sent_a_part_content_to_one_peer();  //发送一个基本单位内容给其中一个节点并向客户端下达分发指令
    
    }
    return 0;
}
```