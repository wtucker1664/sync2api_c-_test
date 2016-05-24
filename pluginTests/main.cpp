//
//  main.cpp
//  pluginTests
//
//  Created by Warren Tucker on 28/04/2015.
//  Copyright (c) 2015 Warren Tucker. All rights reserved.
//
/*
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <boost/any.hpp>

using namespace std;
using std::vector;
using std::string;
using std::make_pair;
using std::for_each;
using std::string;
using std::map;
using std::cout;
using std::endl;
struct AnyMap {
    
    void addAnyPair( const std::string& key , boost::any& value );
    
    template<typename T>
    T& get( const std::string key ) {
        return( boost::any_cast<T&>(map_[key]) );
    }
    
    std::map<const std::string, boost::any> map_;
};

void AnyMap::addAnyPair( const std::string& key , boost::any& value ) {
    map_.insert( std::make_pair( key, value ) );
}
//using pointer version of any_cast to avoid exceptions
void retrieve(boost::any & a)
{
    if(string *pstr = boost::any_cast<string>(&a))
    {
        cout<<"string is: "<< *pstr <<endl;
    }
    else if (int *pi = boost::any_cast <int> (&a))
    {
        cout<<"int: "<< *pi <<endl;
    }
    else if (pair <string, int> *pmap=boost::any_cast<pair<string, int> >(&a))
    {
        cout<< "pair<string, int>: " << pmap->first << " " << pmap->second <<endl;
    }
    else
    {
        cout<< "Unknown" << endl;
    }
}

map<int,map<string,string>> trolly;



void print()
{
    map<int,map<string,string>>::iterator it;
    map<string,string>::iterator inner_it;
    
    for ( it=trolly.begin() ; it != trolly.end(); it++ ) {
        cout << "\n\nNew element\n" << (*it).first << endl;
        for( inner_it=(*it).second.begin(); inner_it != (*it).second.end(); inner_it++)
            cout << (*inner_it).first << " => " << (*inner_it).second << endl;
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    map<string,string> bag = *new map<string,string>() ;
    
    bag.insert(make_pair("test","bob"));
    bag.insert(make_pair("test1","sue"));
    trolly.insert(make_pair(0,bag));
    bag.clear();
    
    
    bag.insert(make_pair("test2","dave"));
    bag.insert(make_pair("test3","paul"));
    
    trolly.insert(make_pair(1,bag));
    
    cout << "Number of bags in the trolly: " << trolly.size();
    bag.clear();
    
    print();
    
   // map<1,pair<string,string>> m[1] = p;
    

    //traverse the bag
    
    
    return 0;
}


 #include <iostream>
 #include <vector>
 #include <string>
#include <list>
 
 using namespace std;
 
 class Persons
 {
 public:
	Persons() : name(""), age(0) {}
	Persons(const string &_name, int _age) : name(_name), age(_age) {}
	Persons(const Persons &rhs) : name(rhs.name), age(rhs.age) {}
	Persons operator=(const Persons &rhs)
	{
 if (&rhs == this)
 {
 return *this;
 }
 
 name = rhs.name;
 age = rhs.age;
 return *this;
	}
	
	//Metod: Sets the necessary info
	void SetInfo(const string &_name, int _age)
	{
 name = _name;
 age = _age;
	}
	
	const string &Name() const { return name; }
	int Age() const { return age; }
	
 private:
	string name;
	int age;
 };
 
 
 int main()
 {
	//Create a list with persons and fill it:
 
	vector<Persons> myList;
	myList.push_back(Persons("Charles", 22));
	myList.push_back(Persons("Darwin", 21));
	myList.push_back(Persons("Phytagoras", 75));
	myList.push_back(Persons("Michelle", 65));
	myList.push_back(Persons("Carl", 76));
	myList.push_back(Persons("Cathrine", 54));
	myList.push_back(Persons("Marielle", 25));
	myList.push_back(Persons("Patrick", 85));
	myList.push_back(Persons("Oliver", 48));
	myList.push_back(Persons("Elinette", 52));
     
    list<vector<Persons>> lists;
    lists.push_back(myList);

    for(list<vector<Persons>>::iterator litr = myList.begin(); litr != myList.end(); litr++){
         cout << *litr;
    }
     
	
 }

*/


#include <iostream>
#include <string>
#include <curl/curl.h>
#include <cassert>
#include <exception>
#include <sstream>
#include <stdio.h>
#include <string>
#include <istream>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/foreach.hpp>
#include "LBJSONRenderFM.h"
#include <cstdio>
#include <map>

#include <ostream>




//#include <boost/property_tree/json_parser.hpp>
//
//using boost::property_tree::ptree; using boost::property_tree::read_json; using boost::property_tree::write_json;
//
//using boost::asio::ip::tcp;
using namespace std;
std::stringstream data;
using namespace rapidjson;
using namespace LB;
Document document;	// Default template parameter uses UTF8 and MemoryPoolAllocator.
LBJSONRenderFM *jObject;
static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string createHTTPVarsString(std::string pNames){
    std::stringstream postValues;
    vector<string> strsig;
    boost::split(strsig,pNames,boost::is_any_of(","));
    
    if(strsig.size() > 1){
        
        for(size_t m = 0; m < strsig.size(); m++){
            vector<string> strsig1;
            cout << strsig[m].c_str() << "\n";
            boost::split(strsig1,strsig[m],boost::is_any_of(":,::,|,||,[]"));
            
            if(strsig1.size() == 2){
                
                
                postValues << "&" << strsig1[0].c_str() << "=" << strsig1[1].c_str();
                
            }
        }
        
    }
    
    return postValues.str();
}

void test(){
    
}

LBJSONRenderFM* getObject(){
    
    
    if(jObject == nullptr){
        jObject = new LBJSONRenderFM;
        return jObject;
    }else{
        return jObject;
    }
    
    
}

int main( int argc, char ** argv ) {
//    boost::asio::io_service io_service;
//    tcp::resolver resolver(io_service);
//    tcp::resolver::query query("https://www.sync2api.com/consumer/", "https");
//    tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
//    
//    // Try each endpoint until we successfully establish a connection.
//    tcp::socket socket(io_service);
//    boost::asio::connect(socket, endpoint_iterator);
//    
//    // Form the request. We specify the "Connection: close" header so that the
//    // server will close the socket after transmitting the response. This will
//    // allow us to treat all data up until the EOF as the content.
//    boost::asio::streambuf request;
//    std::ostream request_stream(&request);
//    
//    ptree root;
//    root.put ("sKey", "0b85a3eddf74b32d5b824311537aa4c51e39dff8");
//    root.put ( "scKey", "28cf64e0fc8f5598e51b3585f4769594b87c7f2c");
//    root.put ("method", "twitter");
//    root.put ( "module", "UserTweets");
//    
//    std::ostringstream buf;
//    write_json (buf, root, false);
//    std::string json = buf.str();
//    
//    request_stream << "POST /title/ HTTP/1.1 \r\n";
//    request_stream << "Host:https://www.sync2api.com/consumer/\r\n";
//    request_stream << "User-Agent: C/1.0";
//    request_stream << "Content-Type: application/json; charset=utf-8 \r\n";
//    request_stream << "Accept: */*\r\n";
//    request_stream << "Content-Length: " << json.length() << "\r\n";
//    request_stream << "Connection: close\r\n\r\n";  //NOTE THE Double line feed
//    
//    // Send the request.
//    boost::asio::write(socket, request);
    
//    CURL *curl;
//    CURLcode res;
//    std::string readBuffer;
//    //std::stringstream ss;
//    struct curl_slist *headers=NULL;
//    headers = curl_slist_append(headers, "Accept: application/json");
//    
//    curl = curl_easy_init();
//    if(curl) {
//        //curl_easy_setopt(curl, CURLOPT_URL, "https://www.sync2api.com/consumer/callApi/?cKey=0b85a3eddf74b32d5b824311537aa4c51e39dff8&scKey=28cf64e0fc8f5598e51b3585f4769594b87c7f2c&module=twitter&method=UserTweets&outputType=json");
//        curl_easy_setopt(curl, CURLOPT_URL, "https://www.sync2api.com/consumer/callApi/?cKey=fda44bb00f601a49b9ab4e0ef38e48fa08c3c4a1&scKey=c7be2af49a804edc0eafbf7a0792421e0604cbcf&module=evernote&method=GetNotebook&outputType=json&guid=7d93a4f0-9254-4b1b-9181-f6c04db716f2");
       // curl_easy_setopt(curl, CURLOPT_URL, "http://www.sync2api.com/consumer/callApi/?cKey=19fff6d8e0be431484073a79aa22f812a9234397&scKey=8f7f4f4f811db0550a00e22dfc20c1a050d430a3&module=magento&method=Products&outputType=json&complex_filter[0][key]=created_at&complex_filter[0][value][key]=gt&complex_filter[0][value][value]=2015-04-28");

    
//        
//        
//        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
//        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
//        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
//        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, true);
//        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, true);
//        
//        res = curl_easy_perform(curl);
//        curl_easy_cleanup(curl);
//        
//        
//        const char *json = readBuffer.c_str();
//        std::cout << json << endl;
//        
//        
//#if 0
//        // "normal" parsing, decode strings to new buffers. Can use other input stream via ParseStream().
//        if (document.Parse<0>(json).HasParseError()){
//            
//            return 1;
//            
//        }
//#else
//        // In-situ parsing, decode strings directly in the source string. Source must be string.
//        
//        char *buffer;
//        buffer = const_cast<char *>(json);
//        
//        if (document.ParseInsitu<0>(buffer).HasParseError()){
//            
//            return 1;
//        }
//#endif
    
    
     //   getObject()->setLicenceKeys("0b85a3eddf74b32d5b824311537aa4c51e39dff8","28cf64e0fc8f5598e51b3585f4769594b87c7f2c");
    getObject()->setLicenceKeys("fda44bb00f601a49b9ab4e0ef38e48fa08c3c4a1","c7be2af49a804edc0eafbf7a0792421e0604cbcf"); // warrens test account
    getObject()->clearRequest();
    
    
    //getObject()->setLicenceKeys("070a13d979221d85bae59f4b41d1444d00147b9e","87d4801e9eaaf96f7663650de440472d8dca5c91"); // Live account petrol scooter be careful
//    
       getObject()->setLBDebug(true);
    getObject()->setDebug(true);
        getObject()->setProperty("outputType", "json");
/* Twitter */
    getObject()->setModule("twitter");
    getObject()->setMethod("userTweets");

/* Ebay */
//    getObject()->setModule("ebay");
//    getObject()->setMethod("AddFixedPriceItem");
//    
//    getObject()->setComplexProperty("BuyerRequirmentDetails");
//    getObject()->setComplexProperty("ShipToRegistrationCountry");
//    getObject()->setComplexProperty("true",1);
//    
//    getObject()->setProperty("SKU", "10067");
//    
//    getObject()->setProperty("buyItNowPrice", "5.49");
//    
//    getObject()->setProperty("conditionID", "1000" );
//    
//    getObject()->setProperty("country","GB");
//    
//    getObject()->setProperty("currency", "GBP");
//    
//    getObject()->setProperty("description", "Test" );
//    
//    getObject()->setProperty("dispatchTimeMax", "1");
//    
//    getObject()->setProperty("eBayPrimaryCategoryId","122299");
//    
//    //getObject()->setProperty("encryptDescription", "false");
//    
//    getObject()->setComplexProperty("excludeShipToLocation");
//    getObject()->setComplexProperty("0");
//    getObject()->setComplexProperty("LT",1);
//    
//    getObject()->setProperty("globalShipping","1");
//    
//    getObject()->setProperty("listingDuration", "Days_30");
//    
//    getObject()->setProperty("listingType", "FixedPriceItem");
//    
//    getObject()->setProperty("location","Coventry");
//    
//    getObject()->setProperty("measurementUnit","English");
//    
//    getObject()->setComplexProperty("packageDepth");
//    getObject()->setComplexProperty("measurementSystem");
//    getObject()->setComplexProperty("English",1);
//    
//    getObject()->setComplexProperty("packageDepth");
//    getObject()->setComplexProperty("unit");
//    getObject()->setComplexProperty("token",1);
//    
//    getObject()->setComplexProperty("packageDepth");
//    getObject()->setComplexProperty("value");
//    getObject()->setComplexProperty("",1);
//    
//    getObject()->setComplexProperty("packageLength");
//    getObject()->setComplexProperty("measurementSystem");
//    getObject()->setComplexProperty("English",1);
//    
//    getObject()->setComplexProperty("packageLength");
//    getObject()->setComplexProperty("unit");
//    getObject()->setComplexProperty("token",1);
//    
//    getObject()->setComplexProperty("packageLength");
//    getObject()->setComplexProperty("value");
//    getObject()->setComplexProperty("",1);
//    
//    getObject()->setComplexProperty("packageWidth");
//    getObject()->setComplexProperty("measurementSystem");
//    getObject()->setComplexProperty("English",1);
//    
//    getObject()->setComplexProperty("packageWidth");
//    getObject()->setComplexProperty("unit");
//    getObject()->setComplexProperty("token",1);
//    
//    getObject()->setComplexProperty("packageWidth");
//    getObject()->setComplexProperty("value");
//    getObject()->setComplexProperty("",1);
//    
//    getObject()->setProperty("payPalEmailAddress","test1.test1@linearblue.com");
//    
//    getObject()->setComplexProperty("paymentMethods");
//    getObject()->setComplexProperty("0");
//    getObject()->setComplexProperty("PayPal",1);
//    
//    getObject()->setComplexProperty("pictureDetails");
//    getObject()->setComplexProperty("pictureURL");
//    getObject()->setComplexProperty("0");
//    getObject()->setComplexProperty("http://www.petrolscooter.co.uk/media/import/Images/IMG000031202/IMG000031202.jpg",1);
//    
//    getObject()->setComplexProperty("pictureDetails");
//    getObject()->setComplexProperty("galleryType");
//    getObject()->setComplexProperty("Gallery",1);
//    
//    getObject()->setProperty("postalCode","CV31BX");
//    
//    getObject()->setProperty("quantity","4");
//    
//    getObject()->setComplexProperty("returnPolicy");
//    getObject()->setComplexProperty("returnsAcceptedOption");
//    getObject()->setComplexProperty("ReturnsAccepted",1);
//    
//    getObject()->setComplexProperty("returnPolicy");
//    getObject()->setComplexProperty("returnsWithinOption");
//    getObject()->setComplexProperty("Days_14",1);
//    
//    getObject()->setComplexProperty("returnPolicy");
//    getObject()->setComplexProperty("shippingCostPaidByOption");
//    getObject()->setComplexProperty("Buyer",1);
//    
//    getObject()->setComplexProperty("weightMajor");
//    getObject()->setComplexProperty("measurementSystem");
//    getObject()->setComplexProperty("English",1);
//    
//    getObject()->setComplexProperty("weightMajor");
//    getObject()->setComplexProperty("unit");
//    getObject()->setComplexProperty("token",1);
//    
//    getObject()->setComplexProperty("weightMajor");
//    getObject()->setComplexProperty("value");
//    getObject()->setComplexProperty("0.5",1);
//    
//    getObject()->setProperty("shippingType","Flat");
//    
//    getObject()->setProperty("siteId","3");
//    
//    getObject()->setProperty("startPrice","5.49");
//    
//    getObject()->setProperty("subTitle","Test");
//    
//    getObject()->setProperty("title","Pit Dirt Bike 38mm Double Foam Red Air Filter 110cc 125cc Carburettor Manifold");
//    
//    getObject()->setComplexProperty("shippingServiceInternational");
//    getObject()->setComplexProperty("0");
//    getObject()->setComplexProperty("cost");
//    getObject()->setComplexProperty("50.00",1);
//    
//    getObject()->setComplexProperty("shippingServiceInternational");
//    getObject()->setComplexProperty("0");
//    getObject()->setComplexProperty("location");
//    getObject()->setComplexProperty("0");
//    getObject()->setComplexProperty("Asia",1);
//    
//    getObject()->setComplexProperty("shippingServiceInternational");
//    getObject()->setComplexProperty("0");
//    getObject()->setComplexProperty("priority");
//    getObject()->setComplexProperty("1",1);
//    
//    getObject()->setComplexProperty("shippingServiceInternational");
//    getObject()->setComplexProperty("0");
//    getObject()->setComplexProperty("type");
//    getObject()->setComplexProperty("UK_RoyalMailAirmailInternational",1);
//    
//    getObject()->setComplexProperty("shippingServiceInternational");
//    getObject()->setComplexProperty("0");
//    getObject()->setComplexProperty("shippingServiceAdditionalCost");
//    getObject()->setComplexProperty("cost");
//    getObject()->setComplexProperty("25.00",1);
//    
//    
//    getObject()->setComplexProperty("shippingServiceInternational");
//    getObject()->setComplexProperty("1");
//    getObject()->setComplexProperty("cost");
//    getObject()->setComplexProperty("100.00",1);
//    
//    getObject()->setComplexProperty("shippingServiceInternational");
//    getObject()->setComplexProperty("1");
//    getObject()->setComplexProperty("location");
//    getObject()->setComplexProperty("0");
//    getObject()->setComplexProperty("Europe",1);
//    
//    getObject()->setComplexProperty("shippingServiceInternational");
//    getObject()->setComplexProperty("1");
//    getObject()->setComplexProperty("priority");
//    getObject()->setComplexProperty("3",1);
//    
//    getObject()->setComplexProperty("shippingServiceInternational");
//    getObject()->setComplexProperty("1");
//    getObject()->setComplexProperty("type");
//    getObject()->setComplexProperty("UK_CollectInPersonInternational",1);
//    
//    getObject()->setComplexProperty("shippingServiceInternational");
//    getObject()->setComplexProperty("1");
//    getObject()->setComplexProperty("shippingServiceAdditionalCost");
//    getObject()->setComplexProperty("cost");
//    getObject()->setComplexProperty("0.00",1);
//    
//    
//    
//    getObject()->setComplexProperty("shippingServiceInternational");
//    getObject()->setComplexProperty("2");
//    getObject()->setComplexProperty("cost");
//    getObject()->setComplexProperty("100.00",1);
//    
//    getObject()->setComplexProperty("shippingServiceInternational");
//    getObject()->setComplexProperty("2");
//    getObject()->setComplexProperty("location");
//    getObject()->setComplexProperty("0");
//    getObject()->setComplexProperty("Asia",1);
//    
//    getObject()->setComplexProperty("shippingServiceInternational");
//    getObject()->setComplexProperty("2");
//    getObject()->setComplexProperty("priority");
//    getObject()->setComplexProperty("3",1);
//    
//    getObject()->setComplexProperty("shippingServiceInternational");
//    getObject()->setComplexProperty("2");
//    getObject()->setComplexProperty("type");
//    getObject()->setComplexProperty("UK_CollectInPersonInternational",1);
//    
//    getObject()->setComplexProperty("shippingServiceInternational");
//    getObject()->setComplexProperty("2");
//    getObject()->setComplexProperty("shippingServiceAdditionalCost");
//    getObject()->setComplexProperty("cost");
//    getObject()->setComplexProperty("50.00",1);
//    
//    
//    
//    getObject()->setComplexProperty("shippingService");
//    getObject()->setComplexProperty("0");
//    getObject()->setComplexProperty("cost");
//    getObject()->setComplexProperty("0.00",1);
//    
//    getObject()->setComplexProperty("shippingService");
//    getObject()->setComplexProperty("0");
//    getObject()->setComplexProperty("freeShipping");
//    getObject()->setComplexProperty("true",1);
//    
//    getObject()->setComplexProperty("shippingService");
//    getObject()->setComplexProperty("0");
//    getObject()->setComplexProperty("priority");
//    getObject()->setComplexProperty("1",1);
//    
//    getObject()->setComplexProperty("shippingService");
//    getObject()->setComplexProperty("0");
//    getObject()->setComplexProperty("type");
//    getObject()->setComplexProperty("UK_RoyalMail48",1);
//    
//    getObject()->setComplexProperty("shippingService");
//    getObject()->setComplexProperty("0");
//    getObject()->setComplexProperty("shippingServiceAdditionalCost");
//    getObject()->setComplexProperty("cost");
//    getObject()->setComplexProperty("0.00",1);
//    
//    
//    
//    getObject()->setComplexProperty("shippingService");
//    getObject()->setComplexProperty("1");
//    getObject()->setComplexProperty("cost");
//    getObject()->setComplexProperty("50.00",1);
//    
//    getObject()->setComplexProperty("shippingService");
//    getObject()->setComplexProperty("1");
//    getObject()->setComplexProperty("priority");
//    getObject()->setComplexProperty("2",1);
//    
//    getObject()->setComplexProperty("shippingService");
//    getObject()->setComplexProperty("1");
//    getObject()->setComplexProperty("type");
//    getObject()->setComplexProperty("UK_RoyalMail24",1);
//    
//    getObject()->setComplexProperty("shippingService");
//    getObject()->setComplexProperty("1");
//    getObject()->setComplexProperty("shippingServiceAdditionalCost");
//    getObject()->setComplexProperty("cost");
//    getObject()->setComplexProperty("0.00",1);
//    
//    
//    getObject()->setComplexProperty("shippingService");
//    getObject()->setComplexProperty("1");
//    getObject()->setComplexProperty("cost");
//    getObject()->setComplexProperty("100.00",1);
//    
//    getObject()->setComplexProperty("shippingService");
//    getObject()->setComplexProperty("1");
//    getObject()->setComplexProperty("priority");
//    getObject()->setComplexProperty("3",1);
//    
//    getObject()->setComplexProperty("shippingService");
//    getObject()->setComplexProperty("1");
//    getObject()->setComplexProperty("type");
//    getObject()->setComplexProperty("UK_OtherCourier24",1);
//    
//    getObject()->setComplexProperty("shippingService");
//    getObject()->setComplexProperty("1");
//    getObject()->setComplexProperty("shippingServiceAdditionalCost");
//    getObject()->setComplexProperty("cost");
//    getObject()->setComplexProperty("0.00",1);
    
//    getObject()->setProperty("siteId", "3");
    //getObject()->setProperty("count", "20");
//    getObject()->setProperty("q", "TheTastingHouse");
    
    // Note
   //     getObject()->setProperty("guid", "c0e39e3a-a6e8-4d3f-8a50-6653437a176b");
    
    //getObject()->setProperty("createTimeFrom", "2016-05-01T00:00:00Z");
   // getObject()->setProperty("createTimeTo", "2016-05-21T23:59:59Z");
    // Note book
    
//    getObject()->setProperty("guid", "9cd1ef2c-a694-444d-adea-10400f536be9");
//    
//        getObject()->setModule("evernote");
//        getObject()->setMethod("ListNotes");
    
   // getObject()->setMethod("ListNotebooks");
    
//    getObject()->setComplexProperty("complex_filter");
//    getObject()->setComplexProperty("0");
//    getObject()->setComplexProperty("key");
//    getObject()->setComplexProperty("created_at",1);
//    
//    getObject()->setComplexProperty("complex_filter");
//    getObject()->setComplexProperty("0");
//    getObject()->setComplexProperty("value");
//    getObject()->setComplexProperty("value");
//    getObject()->setComplexProperty("2015-04-28",1);
//    
//    getObject()->setComplexProperty("complex_filter");
//    getObject()->setComplexProperty("0");
//    getObject()->setComplexProperty("value");
//    getObject()->setComplexProperty("key");
//    getObject()->setComplexProperty("gt",1);
    //getObject()->printRequestVars();
    getObject()->sendRequest();
    getObject()->printRecords();
//
//    
//        string r = jObject->getRecordCount();
//        int numb;
//        istringstream ( r ) >> numb;
//        printf("\n\n");
//        for(int i=0; i < numb; i++){
//            cout << jObject->getProperty(i, "text") << endl;
//            cout << jObject->getProperty(i, "id") << endl;
//            printf("\n\n");
//        }
//        printf("\n\n");
//        map<string,string>::iterator inner_it;
//        map<string,string> record = jObject->getAllProperties(10);
//    
//        for( inner_it=record.begin(); inner_it != record.end(); inner_it++){
//        
//            cout << (*inner_it).first << " => " << (*inner_it).second << endl;
//        
//        }
//        printf("\n\n");
//        cout << jObject->getRecordVarNames().str() << endl;
//    
//        printf("\n\n");
//        jObject->clearRequest();
//        jObject->setModule("magento");
//        jObject->setMethod("Products");
//        jObject->sendRequest();
//        jObject->printRecords();
    
        
 //   }
    
    /*
     string varName = 	"CompanyID";
     string value = 	"100";
     fmx::TextAutoPtr setVariable;
     setVariable->Assign("Let ( $" + varName + "=\"" + value + "\" ; 1 )";
     environment.Evaluate(*getDate, result);
     */
    return 0;
}