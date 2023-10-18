
#include "travel.h"
#include <algorithm>

/*template <class TV, int maxNodes>
void setAllColor(Digraph<TV, maxNodes> &g, color_node color) { // Alle Knoten als besucht bzw unbesucht markieren
    int v = g.firstVertex();
    while (v != -1) {
        g.setColor(v, color);
        v = g.nextVertex(v);
    }
}

template <class TV, int maxNodes>
void visit(Digraph<TV, maxNodes> &g, int n) { // Knoten n besuchen
    g.printVertex(n);
}*/

/*template <class TV, int maxNodes>
int Dfs(Digraph<TV, maxNodes> &g, int v,std::vector<int> &dep, int time) {// Tiefensuche ab Knoten v
    if (!g.isVisited(v)) {
        g.setColor(v, GREY); // als besucht markieren
        g.setStart(v, time); // Startzeitpunkt für Knoten setzen
        visit(g, v); // v besuchen
        int w = g.firstArc(v);
        while (w != -1) { // alle Nachfolger von v bearbeiten
            if (!g.isVisited(w)) { // w noch nicht besucht
                time += 1;
                time = Dfs(g, w, dep, time); // Tiefensuche für w starten
            } else { //Kantenmarkierungen setzen
                if (g.getColor(w) == GREY)
                    g.setArcWeight(v, w, weightBackEdge); //Rückwärtskante
                else if (g.getColor(w) == BLACK) {
                    if (g.getStart(v) < g.getEnd(w))
                        g.setArcWeight(v, w, weightForwardEdge); // Forwardkante
                    else
                        g.setArcWeight(v, w, weightCrossEdge); //Crosskante
                }
            }
            w = g.nextArc(v, w);
        }
        time += 1;
        g.setColor(v, BLACK);
        dep.push_back(v);
        g.setEnd(v, time);
        visit(g, v);
    }
    return time;
}

template <class TV, int maxNodes>
void DepthFirstSearch(Digraph<TV, maxNodes> &g, std::vector<int> &dep) { // Tiefensuche
    int time = 1;
    setAllColor(g, WHITE); // Alle Knoten als unbesucht markieren
    int v = g.firstVertex();
    while (v != -1) {
        if (!g.isVisited(v)) { // v noch nicht besucht
            time = Dfs(g, v, dep, time); // Tiefensuche fuer v starten
            time += 1;
            break;
        }
        v = g.nextVertex(v);
    }
}*/

template <class T, int maxVertices>
void setAllColor(Graph<T, maxVertices> &g, VertexColor color) { // Alle Knoten als besucht bzw unbesucht markieren
    int v = g.firstVertex();
    while (v != -1) {
        g.setColor(v, color);
        v = g.nextVertex(v);
    }
}

template <class T, int maxVertices>
void printVertex(Graph<T, maxVertices> &g, int n) { // Knoten n besuchen
    g.printVertex(n);
}

template <class T, int maxVertices>
int Dfs(Graph<T, maxVertices> &g, int v, std::vector<int> &dep, int time) {// Tiefensuche ab Knoten v
    if (!g.isVisited(v)) {
        g.setColor(v, GREY); // als besucht markieren
        g.setStart(v, time); // Startzeitpunkt für Knoten setzen
        printVertex(g, v); // v besuchen
        int w = g.firstEdge(v);
        while (w != -1) { // alle Nachfolger von v bearbeiten
            if (!g.isVisited(w)) { // w noch nicht besucht
                time += 1;
                time = Dfs(g, w, dep, time); // Tiefensuche fuer w starten
            } else { //Kantenmarkierungen setzen
                if (g.getColor(w) == GREY)
                    g.setEdgeWeight(v, w, weightBackEdge); //Rückwärtskante
                else if (g.getColor(w) == BLACK) {
                    if (g.getStart(v) < g.getEnd(w))
                        g.setEdgeWeight(v, w, weightForwardEdge); // Forwardkante
                    else
                        g.setEdgeWeight(v, w, weightCrossEdge); //Crosskante
                }
            }
            w = g.nextEdge(v, w);
        }
        time += 1;
        g.setColor(v, BLACK);
        dep.push_back(v);
        g.setEnd(v, time);
        printVertex(g, v);
    }
    return time;
}

template <class T, int maxVertices>
void DepthFirstSearch(Graph<T, maxVertices> &g, std::vector<int> &dep) { // Tiefensuche
    int time = 1;
    setAllColor(g, WHITE); // Alle Knoten als unbesucht markieren
    int v = g.firstVertex();
    while (v != -1) {
        if (!g.isVisited(v)) { // v noch nicht besucht
            time = Dfs(g, v, dep, time); // Tiefensuche für v starten
            time += 1;
        }
        v = g.nextVertex(v);
    }
}

long Travel::getId() const
{
    return id;
}

long Travel::getCustomerId() const
{
    return customerId;
}

std::vector<std::shared_ptr<Booking>> Travel::getTravelBookings() const
{
    return travelBookings;
}

void Travel::setTravelBookings(const std::vector<std::shared_ptr<Booking>> &newTravelBookings)
{
    travelBookings = newTravelBookings;
}

void Travel::reihenfolgeBuchung()
{
    int i=0;
    for(auto &buchung : this->travelBookings)
    {
        graph.insertVertex(i, buchung);
        i++;
    }

    int j=0;
    for(auto &buchung : this->travelBookings)
    {
        int k=0;
        int h=0;
        std::string vorgaenger1 = buchung->getPredecorId1();
        std::string vorgaenger2 = buchung->getPredecorId2();
        for(auto &buchung2 : this->travelBookings)
        {
            if(vorgaenger1==buchung2->getId())
            {
                graph.insertEdge(j,k);
                graph.setPredecessor(j,k);
            }
            k++;
        }
        for(auto &buchung2 : this->travelBookings)
        {
            if(vorgaenger2!="0"&&vorgaenger2==buchung2->getId())
            {
                graph.insertEdge(j,h);
                graph.setPredecessor(j,h);
            }
            h++;
        }
        j++;
    }

    dependencies = sortiere();
    std::cout << "irgendwas" << std::endl;
}

std::vector<int> Travel::sortiere()
{
    std::vector<int> vec;
    DepthFirstSearch(graph,vec);
    return vec;
}

bool Travel::checkRoundtrip()
{
    /*std::string startFlugkrzl;
    for(int i=0;i<travelBookings.size();i++)
    {
        std::string typ = bookings[dependencies[i]]->showDetails();
        QString qtyp = QString::fromStdString(typ);
        if(qtyp.contains("Flugbuchung"))
        {
            startFlugkrzl=bookings[dependencies[i]]->myType()[0];
        }
    }*/

    std::vector<std::pair<std::string,std::string>> Flugkrzl;
    for(int i=0;i<dependencies.size();i++)
    {
        std::string typ = travelBookings[dependencies[i]]->showDetails();
        QString qtyp = QString::fromStdString(typ);
        if(qtyp.contains("Flugbuchung"))
        {
            std::pair<std::string,std::string> pair = std::make_pair<>(travelBookings[dependencies[i]]->myType()[0],travelBookings[dependencies[i]]->myType()[1]);
            Flugkrzl.push_back(pair);
        }
    }

    for(int i=0;i<Flugkrzl.size();i++)
    {
        std::cout << Flugkrzl[i].first << " " <<  Flugkrzl[i].second << std::endl;
    }

    if(Flugkrzl.empty()||Flugkrzl.size()==1)
    {
        return false;
    }
    else if(Flugkrzl[0].first==Flugkrzl[Flugkrzl.size()-1].second)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Travel::checkEnoughHotels()
{
    std::vector<std::pair<std::string,std::string>> dates;
    for(int i=0;i<dependencies.size();i++)
    {
        std::string typ = travelBookings[dependencies[i]]->showDetails();
        QString qtyp = QString::fromStdString(typ);
        if(qtyp.contains("Flugbuchung")||qtyp.contains("Hotelreservierung"))
        {
            std::pair<std::string,std::string> datum = std::make_pair<>(travelBookings[dependencies[i]]->getFromDate(),travelBookings[dependencies[i]]->getToDate());
            dates.push_back(datum);
        }
    }
    for(int i=0;i<dates.size();i++)
    {
        std::cout << dates[i].first << " " <<dates[i].second << std::endl;
    }

    bool status=true;
    for(int i=0;i<dates.size();i++)
    {        
        if(dates[i].second!=dates[i+1].first&&i+1<dates.size())
        {
            int fromDate = std::stoi(dates[i+1].first);
            int toDate = std::stoi(dates[i].second);
            if(toDate-fromDate<0)
            {
                return false;
            }
        }
    }

    return status;
}

bool Travel::checkNoUselessHotels()
{
    vector<Info> daten;
    for(int i=0;i<dependencies.size();i++)
    {
        if(typeid(*travelBookings.at(dependencies[i]))==typeid(RentalCarReservation&))
        {
            continue;
        }else
        {
            int fromDate =std::stoi(travelBookings.at(dependencies[i])->getFromDate());
            int toDate =std::stoi(travelBookings.at(dependencies[i])->getToDate());
            if(typeid(*travelBookings.at(dependencies[i]))==typeid(HotelBooking&))
            {
                Info info;
                info.fromDate=fromDate;
                info.toDate=toDate;
                info.type="Hotel";
                daten.push_back(info);
            }
            else
            {
                Info info;
                info.fromDate=fromDate;
                info.toDate=toDate;
                info.type="Flight";
                daten.push_back(info);
            }

        }
    }
    return checkUselessHotel(daten);

    /*std::vector<std::pair<std::string,std::string>> datesHotel;
    std::vector<std::pair<std::string,std::string>> datesFlug;
    for(int i=0;i<dependencies.size();i++)
    {
        std::string typ = travelBookings[dependencies[i]]->showDetails();
        QString qtyp = QString::fromStdString(typ);
        if(qtyp.contains("Hotelreservierung"))
        {
            std::pair<std::string,std::string> datum = std::make_pair<>(travelBookings[dependencies[i]]->getFromDate(),travelBookings[dependencies[i]]->getToDate());
            datesHotel.push_back(datum);
        }
        if(qtyp.contains("Flugbuchung"))
        {
            std::pair<std::string,std::string> datum = std::make_pair<>(travelBookings[dependencies[i]]->getFromDate(),travelBookings[dependencies[i]]->getToDate());
            datesFlug.push_back(datum);
        }
    }

    bool status=true;
    for(int i=0;i<datesHotel.size();i++)
    {
        if(datesHotel[i].first==datesHotel[i+1].first&&i+1<datesHotel.size())
        {
            return false;
        }
    }

    for(int i=0;i<datesFlug.size();i++)
    {
        if(datesFlug[i].first==datesFlug[i+1].first&&i+1<datesFlug.size())
        {
            return false;
        }
    }

    return status;*/
}

bool Travel::checkUselessHotel(vector<Info> &daten)
{
    for(int i=0;i<daten.size();i++)
    {
        if(daten[i].type=="Flight"&&i+1<daten.size())
        {
            int j=indexNaechteFlight(daten,i);
            //hotel in der Mitte
            if(daten[i+1].type=="Hotel"&&j<daten.size())
            {
                if(daten[j].fromDate-daten[i].toDate<daten[i+1].toDate-daten[i+1].fromDate)
                {
                    return false;
                }
            }
            //hotel am ende
            if(daten[i+1].type=="Hotel"&&j>daten.size())
            {
                if(daten[i+1]/*daten[daten.size()-1]*/.fromDate-daten[i].toDate<1)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

int Travel::indexNaechteFlight(vector<Info> &daten, int index)
{
    index++;
    while(index<daten.size())
    {
        if(daten[index].type=="Flight")
        {
            return index;
        }
        index++;
    }
    return 10000;
}

bool Travel::checkNoUselessRentalCars()
{

    vector<Info> daten;
    for(int i=0;i<dependencies.size();i++)
    {
        if(typeid(*travelBookings.at(dependencies[i]))==typeid(HotelBooking&))
        {
            continue;
        }
        else
        {
            int fromDate =std::stoi(travelBookings.at(dependencies[i])->getFromDate());
            int toDate =std::stoi(travelBookings.at(dependencies[i])->getToDate());
            if(typeid(*travelBookings.at(dependencies[i]))==typeid(RentalCarReservation&))
            {
                Info info;
                info.fromDate=fromDate;
                info.toDate=toDate;
                info.type="rentalCar";
                daten.push_back(info);
            }
            else
            {
                Info info;
                info.fromDate=fromDate;
                info.toDate=toDate;
                info.type="Flight";
                daten.push_back(info);
            }

        }
    }
    return checkUselessCar(daten);
    /*std::vector<std::pair<std::string,std::string>> datesRental;
    for(int i=0;i<dependencies.size();i++)
    {
        std::string typ = travelBookings[dependencies[i]]->showDetails();
        QString qtyp = QString::fromStdString(typ);
        if(qtyp.contains("Mietwagenreservierung"))
        {
            std::pair<std::string,std::string> datum = std::make_pair<>(travelBookings[dependencies[i]]->getFromDate(),travelBookings[dependencies[i]]->getToDate());
            datesRental.push_back(datum);
        }
    }

    bool status=true;
    for(int i=0;i<datesRental.size();i++)
    {
        if(datesRental[i].first==datesRental[i+1].first&&i+1<datesRental.size())
        {
            return false;
        }
    }

    return status;*/
}

bool Travel::checkUselessCar(vector<Info> &daten)
{
    for(int i=0;i<daten.size();i++)
    {
        if(daten[i].type=="Flight"&&i+1<daten.size())
        {
            int j=indexNaechteFlight(daten,i);
            if(daten[i+1].type=="rentalCar"&&j<daten.size())
            {
                if(daten[j].fromDate-daten[i].toDate<daten[i+1].toDate-daten[i+1].fromDate)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

Travel::Travel(long ID, long KundeId)
{
    id = ID;
    customerId = KundeId;
}

Travel::~Travel()
{
    /*for(int i = 0;i<(int)travelBookings.size();i++)
    {
        delete travelBookings[i];
    }*/
    travelBookings.clear();
}

void Travel::addBooking(std::shared_ptr<Booking> booking)
{
    for(std::shared_ptr<Booking> existingBooking : travelBookings)
    {
        if(existingBooking->getId()==booking->getId())
        {
            return;
        }
    }
        travelBookings.push_back(booking);
}

/*template <class TV, int maxNodes>
void Bfs(Digraph<TV, maxNodes> &g, int v) { // Breitensuche ab Knoten v
        queue<int> q; // Schlange zum Merken der besuchten Knoten
        if (!g.isVisited(v)) {
        g.setColor(v, GREY); // als besucht markieren
        visit(g, v); // v besuchen
        q.push(v); // Startknoten in Schlange einfuegen
        while (!q.empty()) { // Solange bis Schlange leer
            v = q.front(); // naechsten besuchten Knoten aus Schlange lesen
            q.pop(); // und aus Schlange entfernen
            int w = g.firstArc(v); // erste von v ausgehende Kante
            while (w != -1) { // für alle Nachfolger von v
                if (!g.isVisited(w)) { // w noch nicht besucht
                    g.setColor(w, GREY); // als besucht markieren
                    g.setPredecessor(w, v);
                    visit(g, w); // w besuchen
                    q.push(w); // w in Schlange ablegen
                }
                w = g.nextArc(v, w); // naechste Kante (v,w)
            }
            g.setColor(v, BLACK);
            visit(g, v);
        }
        }
}*/

/*template <class TV, int maxNodes>
void BreadthFirstSearch(Digraph<TV, maxNodes> &g) { // Breitensuche
    setAllColor(g, WHITE); // Alle Knoten als unbesucht markieren
    int v = g.firstVertex();
    while (v != -1) {
        if (!g.isVisited(v)) // v noch nicht besucht
            Bfs(g, v); // Breitensuche fuer v starten
        v = g.nextVertex(v);
        break;}
}*/

