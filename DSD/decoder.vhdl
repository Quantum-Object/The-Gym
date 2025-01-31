library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity PriorityEncoder4To2 is 
port (
    A : IN  STD_LOGIC_VECTOR(3 downto 0);
    B : OUT STD_LOGIC_VECTOR(1 downto 0)
);end PriorityEncoder4To2;


architecture behave of PriorityEncoder4To2 is
    begin
        b <= "11" when a(3) = '1' else
             "10" when a(2) = '1' else
             "01" when a(1) = '1' else
             "00" when a(0) = '1' else
             "XX"; -- Default value if no inputs are active
    end behave;


