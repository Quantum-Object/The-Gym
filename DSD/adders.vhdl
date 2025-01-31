library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

------HALF ADDER-------

entity HA is 
port (
    A: IN STD_LOGIC;
    B: IN STD_LOGIC;
    C: OUT STD_LOGIC;
    S: OUT STD_LOGIC
);
end HA;


architecture HA_b of HA is 
begin
    S <= B xor A;
    C <= A and B;
end HA_b;

-----------FULL ADDER----------------

entity FA is 
port(
    A: IN STD_LOGIC;
    B: IN STD_LOGIC;
    Cin: IN STD_LOGIC;
    Cout:OUT STD_LOGIC;
    S: OUT STD_LOGIC
);
end FA;


architecture FA_b of FA is 

--- we declare HA 1st---
component HA port (
    A: IN STD_LOGIC;
    B: IN STD_LOGIC;
    C: OUT STD_LOGIC;
    S: OUT STD_LOGIC
);end component;


---signal used:
Signal s1,c2,c1: STD_LOGIC;


begin
    HA1 : HA port map(A,B,c1,s1);
    HA2 : HA port map(s1,Cin,c2,S);
    Cout <= c2 OR c1;
end FA_b;


----- 4-BIT RIPPLE CARRY ADDER -----
entity 4BA is
    Port (
        a : IN STD_LOGIC_VECTOR(3 downto 0);
        b : IN STD_LOGIC_VECTOR(3 downto 0);
        cin : IN STD_LOGIC;
        sum : OUT STD_LOGIC_VECTOR(3 downto 0);
        cout : OUT STD_LOGIC
    );
end 4BA;

architecture addition of 4BA is

    -- Component declaration for the Full Adder (FA)
    component FA
        Port (
            A : IN STD_LOGIC;
            B : IN STD_LOGIC;
            Cin : IN STD_LOGIC;
            Cout : OUT STD_LOGIC;
            S : OUT STD_LOGIC
        );
    end component;

    -- Signal to connect carry outputs from each Full Adder
    signal c : STD_LOGIC_VECTOR(3 downto 0);

begin

    -- Instantiation of Full Adders
    FA1: FA port map (A => a(0), B => b(0), Cin => cin, Cout => c(0), S => sum(0));
    FA2: FA port map (A => a(1), B => b(1), Cin => c(0), Cout => c(1), S => sum(1));
    FA3: FA port map (A => a(2), B => b(2), Cin => c(1), Cout => c(2), S => sum(2));
    FA4: FA port map (A => a(3), B => b(3), Cin => c(2), Cout => c(3), S => sum(3));

    -- Final carry-out is the carry output from the last full adder
    cout <= c(3);

end addition;



-------- same but for generate-----


begin
    FA1: FA port map (A => a(0), B => b(0), Cin => cin, Cout => c(0), S => sum(0));
    gloop :for i in 1 to 3 generate
    FAi: FA port map (A => a(i), B => b(i), Cin => c(i-1), Cout => c(i), S => sum(i));
    end generate gloop;
    cout <= c(3);

    ------ cool thing we can do is that -----
     c=> (if i=0 then cin else c(i-1));
    -----------
end addition;

-------end-----;