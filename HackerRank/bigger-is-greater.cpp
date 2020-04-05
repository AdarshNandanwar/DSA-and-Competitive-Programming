#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin>>n;
    while(n--){
        string str;
        cin>>str;
        bool done = false;
        ll length = str.length();
        for (ll last_index = length - 1; last_index > 0; last_index--)
        {
            for(ll i = last_index - 1; i >= 0; i--){
                if(str[last_index] >= str[i]){
                    string prev_str = str;
                    char temp = str[last_index];
                    str[last_index] = str[i];
                    str[i] = temp;
                    string prefix = str.substr(0, i+1), suffix = str.substr(i+1);
                    sort(suffix.begin(), suffix.end());
                    str = prefix + suffix;
                    if(str != prev_str){
                        done = true;
                        break;
                    }
                }
            }
            if(done){
                cout<<str<<endl;
                break;
            }
        }
        if(!done){
            cout<<"no answer"<<endl;
        }
    }
    return 0;
}

// Test Case bought

// 100
// imllmmcslslkyoegymoa
// fvincndjrurfh
// rtglgzzqxnuflitnlyit
// mhtvaqofxtyrz
// zalqxykemvzzgaka
// wjjulziszbqqdcpdnhdo
// japjbvjlxzkgietkm
// jqczvgqywydkunmjw
// ehdegnmorgafrjxvksc
// tydwixlwghlmqo
// wddnwjneaxbwhwamr
// pnimbesirfbivxl
// mijamkzpiiniveik
// qxtwpdpwexuej
// qtcshorwyck
// xoojiggdcyjrupr
// vcjmvngcdyabcmjz
// xildrrhpca
// rrcntnbqchsfhvijh
// kmotatmrabtcomu
// bnfcejmyotvw
// dnppdkpywiaxddoqx
// tmowsxkrodmkkra
// jfkaehlegohwggf
// ttylsiegnttymtyx
// kyetllczuyibdkwyihrq
// xdhqbvlbtmmtshefjf
// kpdpzzohihzwgdfzgb
// kuywptftapaa
// qfqpegznnyludrv
// ufwogufbzaboaepslikq
// jfejqapjvbdcxtkry
// sypjbvatgidyxodd
// wdpfyqjcpcn
// baabpjckkytudr
// uvwurzjyzbhcqmrypraq
// kvtwtmqygksbim
// ivsjycnooeodwpt
// zqyxjnnitzawipqsm
// blmrzavodtfzyepz
// bmqlhqndacv
// phvauobwkrcfwdecsd
// vpygyqubqywkndhpzw
// yikanhdrjxw
// vnpblfxmvwkflqobrk
// pserilwzxwyorldsxksl
// qymbqaehnyzhfqpqprpl
// fcakwzuqlzglnibqmkd
// jkscckttaeifiksgkmxx
// dkbllravwnhhfjjrce
// imzsyrykfvjt
// tvogoocldlukwfcajvix
// cvnagtypozljpragvlj
// hwcmacxvmus
// rhrzcpprqccf
// clppxvwtaktchqrdif
// qwusnlldnolhq
// yitveovrja
// arciyxaxtvmfgquwb
// pzbxvxdjuuvuv
// nxfowilpdxwlpt
// swzsaynxbytytqtq
// qyrogefleeyt
// iotjgthvslvmjpcchhuf
// knfpyjtzfq
// tmtbfayantmwk
// asxwzygngwn
// rmwiwrurubt
// bhmpfwhgqfcqfldlhs
// yhbidtewpgp
// jwwbeuiklpodvzii
// anjhprmkwibe
// lpwhqaebmr
// dunecynelymcpyonjq
// hblfldireuivzekegit
// uryygzpwifrricwvge
// kzuhaysegaxtwqtvx
// kvarmrbpoxxujhvgpw
// hanhaggqzdpunkugzmhq
// gnwqwsylqeuqr
// qzkjbnyvclrkmdtc
// argsnaqbquv
// obbnlkoaklcx
// ojiilqieycsasvqosycu
// qhlgiwsmtxbffjsxt
// vvrvnmndeogyp
// ibeqzyeuvfzb
// sajpyegttujxyx
// zmdjphzogfldlkgbchnt
// tbanvjmwirxx
// gmdhdlmopzyvddeqyjja
// yxvmvedubzcpd
// soygdzhbckfuk
// gkbekyrhcwc
// wevzqpnqwtpfu
// rbobquotbysufwqjeo
// bpgqfwoyntuhkvwo
// schtabphairewhfmp
// rlmrahlisggguykeu
// fjtfrmlqvsekq