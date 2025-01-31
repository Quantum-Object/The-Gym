library IEEE;
use IEEE.STD_LOGIC_1164.ALL;



entity cir1 is
    port (A,B: IN bit;
        F : out bit);
end cir1;


architecture cir1behave of cir1 is 
begin
    f<=((A and B) or (not A)) xor (A and B);
end cir1behave


 -- AND Gate
entity andgate is 
port( 
    A: in STD_LOGIC;
    B: in STD_LOGIC;
    C: out STD_LOGIC
);
end andgate;

architecture andout of andgate is
begin
C <= A and B;
end andout;

-- OR Gate
entity orgate is 
port( 
    A: in STD_LOGIC;
    B: in STD_LOGIC;
    C: out STD_LOGIC
);
end orgate;

architecture orout of orgate is
begin
C <= A or B;
end orout;

-- NOT Gate
entity notgate is 
port (
    A: in STD_LOGIC;
    C: out STD_LOGIC
);
end notgate;

architecture notout of notgate is 
begin
C <= not A;
end notout;


