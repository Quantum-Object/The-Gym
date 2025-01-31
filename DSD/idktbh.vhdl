library ieee;
use ieee.std_logic_1164.all;

Entity X IS
    Generic (N: integer := 4); -- Default value of N is 4
    Port (
        X_in : IN STD_LOGIC_VECTOR(N-1 downto 0);
        Q : OUT STD_LOGIC
    );
End X;

Entity Y IS 
    Port (
        A : IN STD_LOGIC_VECTOR(15 downto 0);
        B : IN STD_LOGIC_VECTOR(15 downto 0);
        QY : OUT STD_LOGIC_VECTOR(3 downto 0)
    );
End Y;

architecture behaviuor of Y is
    component X is
        Generic (N: integer := 4);
        Port (
            X_in : IN STD_LOGIC_VECTOR(N-1 downto 0);
            Q : OUT STD_LOGIC
        );
    end component;

    Signal T : STD_LOGIC_VECTOR(15 downto 0);

begin
    -- Generate block for larger X instances
    XL: for i in 0 to 3 generate
        X_big: X
            generic map (N => 4) -- Specify the value of N
            port map (
                X_in => T(4*i+3 downto 4*i), -- Correct slicing
                Q => QY(i)
            );

        -- Generate block for smaller X instances inside XL
        XS: for j in 0 to 3 generate
            X_small: X
                generic map (N => 2) -- Specify N=2
                port map (
                    X_in => A(4*i+j) & B(4*i+j), -- Concatenate A and B bits
                    Q => T(4*i+j) -- Assign result to T
                );
        end generate;
    end generate;
end behaviuor;
