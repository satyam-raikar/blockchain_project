pragma solidity ^0.5.1;
pragma experimental ABIEncoderV2;

contract OriginalDevices{
    
    address private owner;
    string[] private devices;
    
    constructor() public{ 
		owner=msg.sender;
		
		
		//devices.push(["device_1","11111111"]);
		/* 
		{
    "Issuer": "ABC Tech",
    "Firmware Version": "v 1.168456546",
    "Device ID": "236Z",
    "Device Model": "A1"
}
		*/
		
		devices.push("d038527a794dc208b8805e708517041c");   /*  { "Issuer": "ABC Tech", "Firmware Version": "v 1.168456546", "Device ID": "236Z", "Device Model": "A1" } */
		devices.push("a0793f8f61e92c48829aa736a7374dc4"); /* { "Issuer": "ABC Tech", "Firmware Version": "v 1.168456546", "Device ID": "300Z", "Device Model": "A1" } */
		devices.push("60bd77ca71dbde7a952077c80b8469b7"); /* { "Issuer": "ABC Tech", "Firmware Version": "v 1.168456546", "Device ID": "989A", "Device Model": "B1" } */
	    devices.push("edf77013aad719754a7b0c4475720652");/*  { "Issuer": "ABC Tech", "Firmware Version": "v 1.168456546", "Device ID": "129A", "Device Model": "B1" }*/
        
    } 
	

// 	//string private device_1 = "11111111";
// 	string private device_2 = "22222222";
// 	string private device_3 = "33333333";
// 	string private device_4 = "44444444";
    
    
    	function getOwner( 
	) public view returns (address) {	 
		return owner; 
	} 
    	function getBalance( 
	) public view returns(uint256){ 
		return owner.balance; 
	} 
    
    function getDeviceKeys() public  view returns(string[]  memory){
         return devices;
    }
    
    
    
}