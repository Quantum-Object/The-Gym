-- filepath: /Users/quantumobject/Desktop/The-Gym/DSD/func.vhdl
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all; -- Add this library for numeric operations

function func (a: std_logic_vector(7 downto 0)) return std_logic_vector is
    variable x: std_logic_vector(3 downto 0);
    variable y: std_logic_vector(3 downto 0);
begin
    x := a(7 downto 4); -- Use := for variable assignment
    y := a(3 downto 0); -- Use := for variable assignment
    if (unsigned(x) > unsigned(y)) then -- Convert to unsigned for comparison
        return y & x;
    else
        return x & "0000";
    end if;
end func;