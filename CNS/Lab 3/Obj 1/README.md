## Objective 1:  
  
### An overview on standard and extended access list.  
  
* ACL is treated as a tool for controlling network traffic by granting or denying access to specific services.  
* It's defined by a set of rules based on IP address & port number.  
* These commands are implemented at router and can be applied to both input & output interface.  
* The 3 components of ACL are:  
    - **Header** - unique identifier of ACL.  
    - **Conditions or Criteria** that has to be applied as ACL.  
    - and **Actions** that specify whether the network traffic should be allowed or denied.  
* There are 2 categories of ACL i.e. **Standard Access List** & **Extended Access List**.  
* **Standard List** is made using source IP Address & they permit or deny the complete system without differentiating between IP Traffic like TCP, UDP, etc. The number range for standard ACL is from 1 to 99.  
* **Extended Access List** are the ACL that uses both source IP address & source prot number and destination IP address & destination port number. In these ACL, specific IP traffic services are differentiated and the number range is from 100 to 199.  