use quad_rand::{gen_range, srand};
use std::time::{SystemTime, UNIX_EPOCH};

const SQUARE: usize = SIZE * SIZE;
const SIZE: usize = 30;

fn main() {
    srand(
        SystemTime::now()
            .duration_since(UNIX_EPOCH)
            .unwrap_or_else(|time| time.duration())
            .as_secs(),
    );

    let mut map = ['#'; SQUARE];
    let (mut px, mut py, mut floor_tiles, mut tunnel_len, mut tunnel_dir, mut i) =
        (gen_range(0, SIZE), gen_range(0, SIZE), SQUARE / 3, 0, 0, 0);

    while floor_tiles > 0 {
        match if tunnel_len > 0 {
            tunnel_dir
        } else {
            gen_range(0, 8)
        } {
            0 => {
                if px + 1 == SIZE - 1 {
                    px -= 1
                } else {
                    px += 1
                }
            }
            1 => {
                if px - 1 == 0 {
                    px += 1
                } else {
                    px -= 1
                }
            }
            2 => {
                if py + 1 == SIZE - 1 {
                    py -= 1
                } else {
                    py += 1
                }
            }
            3 => {
                if py - 1 == 0 {
                    py += 1
                } else {
                    py -= 1
                }
            }
            _ => {
                tunnel_dir = gen_range(0, 4);
                tunnel_len = gen_range(0, SIZE / 5);
            }
        }

        map[py * SIZE + px] = '.';
        if tunnel_len > 0 {
            tunnel_len -= 1;
        } else {
            floor_tiles -= 1;
        }
    }

    let mut last = 'Z';
    while i < SIZE {
        let index = gen_range(0, SQUARE);
        if map[index] == '.' {
            map[index] = if i < SIZE / 2 && last != '!' {
                '!'
            } else {
                'Z'
            };
            last = map[index];
            i += 1;
        }
    }

    map[py * SIZE + px] = '<';
}
