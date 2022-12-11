import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.function.Function;

class Monkey {
    public ArrayList<Long> items;
    public Function<Long, Long> operation;
    public int targetIfTrue;
    public int targetIfFalse;
    public int divisor;

    public int itemsInspected = 0;

    public Monkey(List<Integer> items, Function<Long, Long> operation, Integer divisor, Integer targetIfTrue, Integer targetIfFalse) {
        this.items = new ArrayList<>();
        items.forEach((item) -> this.items.add((long) item)); // Couldn't bother changing the lists from int to long

        this.operation = operation;
        this.divisor = divisor;
        this.targetIfTrue = targetIfTrue;
        this.targetIfFalse = targetIfFalse;
    }

    public void turn(Monkey[] monkeys, Integer lcm) {
        for (Long item : items) {
            item = this.operation.apply(item);
            if (lcm == null) {
                item /= 3;
            } else {
                item = item % lcm;
            }

            int target = item % divisor == 0 ? targetIfTrue : targetIfFalse;
            monkeys[target].items.add(item);
            itemsInspected++;
        }
        this.items.clear();
    }
}

class Aoc11 {
    public static Monkey[] initializeMonkeys() {
        Monkey[] monkeys = new Monkey[8]; 
        monkeys[0] = new Monkey(Arrays.asList(72, 97), x -> x * 13, 19, 5, 6);
        monkeys[1] = new Monkey(Arrays.asList(55, 70, 90, 74, 95), x -> x * x, 7, 5, 0);
        monkeys[2] = new Monkey(Arrays.asList(74, 97, 66, 57), x -> x + 6, 17, 1, 0);
        monkeys[3] = new Monkey(Arrays.asList(86, 54, 53), x -> x + 2, 13, 1, 2);
        monkeys[4] = new Monkey(Arrays.asList(50, 65, 78, 50, 62, 99), x -> x + 3, 11, 3 , 7);
        monkeys[5] = new Monkey(Arrays.asList(90), x -> x + 4, 2, 4, 6);
        monkeys[6] = new Monkey(Arrays.asList(88, 92, 63, 94, 96, 82, 53, 53), x -> x + 8, 5, 4, 7);
        monkeys[7] = new Monkey(Arrays.asList(70, 60, 71, 69, 77, 70, 98), x -> x * 7, 3, 2, 3);
        return monkeys;
    }
    public static void printResult(String message, Monkey[] monkeys) {
        long best = 0, secondBest = 0;
        for (Monkey m : monkeys) {
            if (m.itemsInspected > best) {
                secondBest = best;
                best = m.itemsInspected;
            } else if (m.itemsInspected > secondBest) {
                secondBest = m.itemsInspected;
            } 
        }
        System.out.println(message + best * secondBest);
    }

    public static void main(String[] args) {
        Monkey[] monkeys = initializeMonkeys();
        for (int i = 0; i < 20; i++) {
            for (Monkey m : monkeys) {
                m.turn(monkeys, null);
            }
        }
        printResult("Part 1: ", monkeys);

        monkeys = initializeMonkeys();
        int lcm = 1;
        for (Monkey m : monkeys) {
            lcm *= m.divisor;
        }
        for (int i = 0; i < 10000; i++) {
            for (Monkey m : monkeys) {
                m.turn(monkeys, lcm);
            }
        }
        printResult("Part 2: ", monkeys);

    }
}