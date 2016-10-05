--
-- Test
--
-- Things to add, current build/fuzz jobs.
-- Functions for email
-- Ways to configure, like:
-- set_conf("git_pass", "git@github.com/password-store")
-- Find a way to easly send variables over USB to this.
-- something like: usb_get("NAME", "TYPE");

nprint(6, 0, 3, "[Private]");
nprint(4, 1, 3, "Email: ");
nprint(1, 1, 11, "42")

nprint(6, 0, 20, "[Work]");
nprint(4, 1, 20, "Email: ");
nprint(1, 1, 28, "4");

-- nprint(4, 2, 3, "Jobs:");
-- nprint(6, 2, 11, "4")
-- nprint(4, 2, 13, "due")
-- nprint(6, 2, 20, "12")
-- nprint(4, 2, 23, "total")


--
-- Should be able to detect the applications running on $HOST.
-- To load profiles based on that.
-- Windows driver can parse the process structure to determine the required variables.
-- COOL idea, harvest credentails from ILASS process and show them on screen. For kicks.
--

doom = true

if doom == true then
    nprint(4, 4, 0, "DOOM: ");
    nprint(4, 5, 3, "Health: ");
    nprint(2, 5, 12, "200")
    nprint(4, 6, 3, "Armour: ");
    nprint(2, 6, 12, "100")

    nprint(4, 5, 20, "Ammo: ");
    nprint(2, 5, 30, "60")

    nprint(4, 6, 20, "Weapon: ");
    nprint(5, 6, 30, "Teslacannon");
end
