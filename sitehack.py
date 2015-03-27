import urllib2
import sys
import copy
TARGET = 'http://crypto-class.appspot.com/po?er='
#--------------------------------------------------------------
# padding oracle
#--------------------------------------------------------------
class PaddingOracle(object):
    def query(self, q):
        target = TARGET + urllib2.quote(q)    # Create query URL
        req = urllib2.Request(target)         # Send HTTP request to server
        try:
            f = urllib2.urlopen(req)          # Wait for response
        except urllib2.HTTPError, e:          
            print "We got: %d" % e.code       # Print response code
            if e.code == 404:
                return True # good padding
            return False # bad padding

if __name__ == "__main__":
    correct_data = []
    po = PaddingOracle()
    text  = "f20bdba6ff29eed7b046d1df9fb7000058b1ffb4210a580f748b4ac714c001bd4a61044426fb515dad3f21f18aa577c0bdf302936266926ff37dbf7035d5eeb4"
    datalen  = len(text)/2
    data3  = []
    for i in range(0,datalen):
        a = text[2*i:2*i+2]
        data3.append(int(a,16))
    m=  ''.join('{:02x}'.format(x) for x in data3)
    print m
    data = data3[32:]
    data2 = copy.copy(data)
    for j in range(0,16):
        for i in range (15,15-j,-1):
            data2[i] = data2[i]^j+1^j
        for i in range(0,256):
            data2[0:16-j] = data[0:16-j]
            data2[15-j] = (data2[15-j]^(j+1)^i)%256
            temp = ''.join('{:02x}'.format(x) for x in data3[0:32]+data2)
            print temp
            if j == 8 and i == 9:
                correct_data.append(i)
                break
            if (po.query(temp) == True):
                correct_data.append(i)
                break
        
        print correct_data
    print correct_data
