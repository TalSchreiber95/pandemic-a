#include "Board.hpp"

using namespace std;
using namespace pandemic;

int& Board::operator[](City c) {
    return diseasBox[c];
}

bool Board::is_clean() {
    for(auto& di: diseasBox) {
        if(di.second > 0) {
            return false;
        }
    }
    return true;
}

bool Board::is_connected(City& c1, City& c2) {
    return connections.at(c1).contains(c2);
}

void Board::update_research_station(City c) {
    researchStations.insert(c);
}

bool Board::is_research_station(City c) {
    return researchStations.contains(c);
}

void Board::mark_cured(Color c) {
    medicine[c] = true;
}

bool Board::is_cure_discoverd(City c) {
    return medicine[colorOf(c)];
}

Color Board::colorOf(City c) {
    return cities_colors.at(c);
}

ostream& pandemic::operator<<(ostream& out, const Board& b) {
    out <<  "__________________________ BOARD _________________________"<<endl<<endl;
    out <<  "level of disease:"  << endl;
    for(auto& di: b.diseasBox) {
        out <<"  ["<<di.second<<"] "<< cityToString(di.first)<<endl;
    }
    out << endl;
    out << "Cure discovered:"  << endl;
    for(int i = 0; i < 4; i++) {
        out<<"  [" <<b.medicine[i]<<"] "<<  colorToString(i) <<endl;
    }
    out << endl;
    int j=1;
    out <<  "Research stations:" << endl;
    for(auto& rs: b.researchStations) {
        out <<"  "<<j++<<"."<<  cityToString(rs) << endl;
    }
    out <<  "________________________ END BOARD ________________________"  <<endl;
    return out;
}

map<City, set<City>> Board::connections {
    { Algiers, {Madrid, Paris, Istanbul, Cairo } },
    { Atlanta, {Chicago, Miami, Washington } },
    { Baghdad, {Tehran, Istanbul, Cairo, Riyadh, Karachi } },
    { Bangkok, {Kolkata, Chennai, Jakarta, HoChiMinhCity, HongKong } },
    { Beijing, {Shanghai, Seoul } },
    { Bogota, {MexicoCity, Lima, Miami, SaoPaulo, BuenosAires } },
    { BuenosAires, {Bogota, SaoPaulo } },
    { Cairo, {Algiers, Istanbul, Baghdad, Khartoum, Riyadh } },
    { Chennai, {Mumbai, Delhi, Kolkata, Bangkok, Jakarta } },
    { Chicago, {SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal } },
    { Delhi, {Tehran, Karachi, Mumbai, Chennai, Kolkata } },
    { Essen, {London, Paris, Milan, StPetersburg } },
    { HoChiMinhCity, {Jakarta, Bangkok, HongKong, Manila } },
    { HongKong, {Bangkok, Kolkata, HoChiMinhCity, Shanghai, Manila, Taipei } },
    { Istanbul, {Milan, Algiers, StPetersburg, Cairo, Baghdad, Moscow } },
    { Jakarta, {Chennai, Bangkok, HoChiMinhCity, Sydney } },
    { Johannesburg, {Kinshasa, Khartoum } },
    { Karachi, {Tehran, Baghdad, Riyadh, Mumbai, Delhi } },
    { Khartoum, {Cairo, Lagos, Kinshasa, Johannesburg } },
    { Kinshasa, {Lagos, Khartoum, Johannesburg } },
    { Kolkata, {Delhi, Chennai, Bangkok, HongKong } },
    { Lagos, {SaoPaulo, Khartoum, Kinshasa } },
    { Lima, {MexicoCity, Bogota, Santiago } },
    { London, {NewYork, Madrid, Essen, Paris } },
    { LosAngeles, {SanFrancisco, Chicago, MexicoCity, Sydney } },
    { Madrid, {London, NewYork, Paris, SaoPaulo, Algiers } },
    { Manila, {Taipei, SanFrancisco, HoChiMinhCity, Sydney } },
    { MexicoCity, {LosAngeles, Chicago, Miami, Lima, Bogota } },
    { Miami, {Atlanta, MexicoCity, Washington, Bogota } },
    { Milan, {Essen, Paris, Istanbul } },
    { Montreal, {Chicago, Washington, NewYork } },
    { Moscow, {StPetersburg, Istanbul, Tehran } },
    { Mumbai, {Karachi, Delhi, Chennai } },
    { NewYork, {Montreal, Washington, London, Madrid } },
    { Osaka, {Taipei, Tokyo } },
    { Paris, {Algiers, Essen, Madrid, Milan, London } },
    { Riyadh, {Baghdad, Cairo, Karachi } },
    { SanFrancisco, {LosAngeles, Chicago, Tokyo, Manila } },
    { Santiago, {Lima } },
    { SaoPaulo, {Bogota, BuenosAires, Lagos, Madrid } },
    { Seoul, {Beijing, Shanghai, Tokyo } },
    { Shanghai, {Beijing, HongKong, Taipei, Seoul, Tokyo } },
    { StPetersburg, {Essen, Istanbul, Moscow } },
    { Sydney, {Jakarta, Manila, LosAngeles } },
    { Taipei, {Shanghai, HongKong, Osaka, Manila } },
    { Tehran, {Baghdad, Moscow, Karachi, Delhi } },
    { Tokyo, {Seoul, Shanghai, Osaka, SanFrancisco } },
    { Washington, {Atlanta, NewYork, Montreal, Miami } }
};