library ieee;
use ieee.std_logic_1164.all;

entity GreyCode is 
port (A : IN STD_LOGIC_VECTOR(3 downto 0);
      G : OUT STD_LOGIC_VECTOR(3 downto 0));
end GreyCode;


architecture behave of GreyCode is 

begin 
process(A)
    begin
    G(3) <=A(3);
    l : for i in 3 downto 1 loop 
        G(i-1) <=A(i-1) XOR A(i);
    end loop;
end process
end behave ;