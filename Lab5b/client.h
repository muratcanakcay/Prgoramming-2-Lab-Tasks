#ifndef KLIENT_H_
#define KLIENT_H_

class Client
{
private:
	int arrival_time;    // time the client joins the queue
	int service_time;		// client service time
		
public:
	Client();
	void set(long arrival_time);
	int what_time() const { return arrival_time; }
	int how_long() const { return service_time; }
	friend ostream& operator<<(ostream&, const Client&);
};

#endif