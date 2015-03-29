# Atomic Time: This program will get the true atomic time from an atomic time clock on the Internet.
# Use any one of the atomic clocks returned by a simple Google search

# (Uses ntplib)
import ntplib
from time import ctime

def main():
	client = ntplib.NTPClient()
	response = client.request('europe.pool.ntp.org', version=3)
	
	print("The time is", ctime(response.tx_time))

if __name__ == "__main__":
	main()