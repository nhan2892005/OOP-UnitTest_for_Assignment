/*

*/

#ifndef _H_STUDY_IN_PINK_2_H_
#define _H_STUDY_IN_PINK_2_H_

#include "main.h"

// Forward declaration
/*
    Khai báo trước - Định nghĩa sau
    Chúng ta khai báo trước các class để trong quá trình định nghĩa
    sẽ không xảy ra việc không khai báo trước
*/
//Dưới đây sẽ là các class các bạn cần thực hiện

/*
Khởi tạo một bản đồ (ma trận) 
dùng để cho các đối tượng di chuyển trong ma trận này
*/
class MapElement;   // Mỗi phần tử là một ô trong bản đồ
class Map;          // Bản đồ lớn chứa các phần tử
class Position;     // Dùng để truy xuất đến các phần tử trong bản đồ, 
                        //VD: Position pos_of_Nhan = Position(2,5);
 
/*
Class MovingObject dùng để biểu diễn các đối tượng có thể di chuyển được trong bản đồ
Trong đó, những đối tượng có thể di chuyển được là:
Sherlock, Watson, Criminal, Robot
Vì vậy các class này phải kế thừa từ MovingObject
Tuy nhiên, khi đọc các phần tiếp theo, mình phát hiện đề yêu cầu
    SherLock, Watson, Criminal kế thừa từ Character
    Character kế thừa từ MovingObject
Nên mình sẽ thiết lập như sau:
class MovingObject
{};
    class Character : public MovingObject
    {};
        class Sherlock : public Character
        {};
        class Watson : public Character
        {};
        class Criminal : public Character
        {};
Phần Robot thì kế thừa từ MovingObject, đây là 1 phần lớn nên mình sẽ nêu sau.
*/
 class MovingObject;
 class Character;
 class Sherlock;
 class Watson;
 class Criminal;

//Đây là một mảng chứa những đối tượng đang di chuyển trên bản đồ, 
//đối tượng nào được chèn vào trước thì sẽ được xếp trước
 class ArrayMovingObject;

//Đây là một class để đọc input từ file vào và phân tích các dữ liệu để lấy input
 class Configuration;

//Như đã nói, Robot là 1 class kế thừa từ MovingObject và 
//dĩ nhiên nó cũng sẽ được thêm vào ArrayMovingObject khi được tạo ra
//Các đối tượng Robot con sẽ được kế thừa từ Robot
//Cách thiết kế tương tự như MovingObject
 class Robot;
 class RobotC;
 class RobotS;
 class RobotW;
 class RobotSW;

//Đây là một class biểu diễn đồ vật
//Các class con tượng trưng cho các đồ vật, mỗi loại sẽ có cách sử dụng và yêu cầu khác nhau
 class BaseItem;
 class MagicBook;
 class EnergyDrink;
 class FirstAid;
 class ExcemptionCard;
 class PassingCard;

//Đây là class biểu diễn túi đồ, các đồ vật sẽ nằm trong túi đồ này
//Các class kế thừa tương tự như các class trước
//Đây chính là class sẽ hiện thực danh sách liên kết
//Hãy tưởng tượng mỗi túi đồ chứa một vật và có các tính năng
//  Có 1 sợi dây liên kết các túi đồ lại với nhau
//  [Túi đồ head]->[Túi đồ]->[Túi đồ]->[Túi đồ]->[Túi đồ tail]
 class BaseBag;
 class SherlockBag;
 class WatsonBag;

//Class để chạy chương trình của chính mình
 class StudyPinkProgram;

//Class này không cần quá chú ý, chỉ cần khai báo, có thể dùng để làm 1 bộ test
 class TestStudyInPink;


enum ItemType { MAGIC_BOOK, ENERGY_DRINK, FIRST_AID, EXCEMPTION_CARD, PASSING_CARD };
enum ElementType { PATH, WALL, FAKE_WALL };
enum RobotType { C=0, S, W, SW };

//Tiến hành hiện thực các class
//Đọc yêu cầu đề, định nghĩa trước các phương thức, thuộc tính trong class, 
//sau đó định nghĩa chi tiết ở file cpp
//Dưới đây chỉ là tham khảo, các bạn phải hiện thực hết tất cả các phương thức trong tất cả class
//Các bạn phải đọc đề, kỹ, chi tiết để thực hiện từng class
class MapElement
{
    public:
        friend class TestStudyInPink;
        //Luôn luôn thiết lập hàm bạn TestStudyPink, điều này sẽ không nhắc lại
        MapElement(ElementType in_type);
        virtual ~MapElement();
        virtual ElementType getType() const;
    protected:
        ElementType type;
};

class Path : public MapElement
{
    public:
        friend class TestStudyInPink;
        Path();
};

class Wall : public MapElement
{
    public:
        friend class TestStudyInPink;
        Wall();
};

class FakeWall : public MapElement
{
    public:
        friend class TestStudyInPink;
        FakeWall(int in_req_exp);
        int getReqExp() const;
    private:
        int req_exp;
};

class Map
{
    public:
        friend class TestStudyInPink;
        Map(int num_rows , 
            int num_cols , 
            int num_walls , 
            Position * array_walls , 
            int num_fake_walls , 
            Position * array_fake_walls);
        ~Map();
        bool isValid(const Position & pos , MovingObject * mv_obj) const;
    private:
        int num_rows, num_cols;
        MapElement*** map;
};

class Position
{
    public:
        friend class TestStudyInPink;
        Position(int r=0, int c=0);
        Position(const string & str_pos);
        int getRow() const;
        int getCol() const;
        void setRow(int r);
        void setCol(int c);
        string str() const;
        bool isEqual(int in_r, int in_c) const;
        bool isEqual(Position pos);
        static const Position npos;
    private:
        int r, c;
};

class MovingObject
{
    public:
        friend class TestStudyInPink;
        MovingObject(   int index , 
                        const Position pos , 
                        Map * map , 
                        const string & name="");
        virtual ~MovingObject();
        virtual Position getNextPosition() = 0;
        virtual Position getCurrentPosition() const = 0;
        virtual void move() = 0;
        virtual string str() const = 0;
    protected:
        int index;
        Position pos;
        Map * map;
        string name;  
};

class Character : public MovingObject
{
    public:
        Character(  int index,
                    const Position & init_pos,
                    Map * map,
                    bool pass,
                    const string & name="");
        virtual ~Character();
        virtual int getEXP() = 0;
        virtual int getHP() = 0;
        virtual void changeEXP(double change) = 0;
        virtual void changeHP(double change) = 0;
        virtual void meetRobot(MovingObject* robot) = 0;
        Position Criminal_pos;
    private:
        bool pass;
};
                            /*
                                HCMUT 14:34 10/03/2024
                                Class Position
                                Done
                            */
class Sherlock : public Character
{
    public:
        friend class TestStudyInPink;
        Sherlock(   int index , 
                    const string & moving_rule , 
                    const Position & init_pos , 
                    Map * map , 
                    int init_hp , 
                    int init_exp);
        ~Sherlock();
        Position getNextPosition();
        void move();
        string str() const;
    private:
        string moving_rule;
        int hp, exp;
};

class Watson : public Character
{
    public:
        friend class TestStudyInPink;
        Watson( int index , 
                const string & moving_rule , 
                const Position & init_pos , 
                Map * map , 
                int init_hp , 
                int init_exp);
        Position getNextPosition();
        void move();
        string str() const;
        ~Watson();
    private:
        string moving_rule;
        int hp, exp;
};

class Criminal : public MovingObject
{
    public:
        friend class TestStudyInPink;
        Criminal(   int index , 
                    const Position & init_pos , 
                    Map * map , 
                    Sherlock * sherlock , 
                    Watson * watson);
        Position getNextPosition();
        void move();
        string str() const;
        ~Criminal();
    private:
        Sherlock * sherlock;
        Watson * watson;
};

class ArrayMovingObject
{
    public:
        friend class TestStudyInPink;
        ArrayMovingObject(int capacity);
        ~ArrayMovingObject();
        bool isFull() const;
        bool add(MovingObject * mv_obj);
        string str() const;
        MovingObject * get(int i);
    private:
        MovingObject** arr_mv_objs;
        int count;
        int capacity;
};

class Configuration
{
    public:
        friend class TestStudyInPink;
        Configuration(const string & filepath);
        ~Configuration();
        string str() const;
    private:
        int map_num_rows, map_num_cols;
        int max_num_moving_objects;
        int num_walls = 0;
        Position* arr_walls;
        int num_fake_walls = 0;
        Position* arr_fake_walls;
        string sherlock_moving_rule;
        Position sherlock_init_pos;
        int sherlock_init_hp;
        int sherlock_init_exp;
        string watson_moving_rule;
        Position watson_init_pos;
        int watson_init_hp;
        int watson_init_exp;
        Position criminal_init_pos;
        int num_steps; 
};

class Robot : public MovingObject
{
    public:
        Robot(  int index,
                const Position &init_pos,
                Map * map,
                RobotType robot_type);
        virtual Position getNextPosition() = 0;
        void move();
        virtual string str() const;
        RobotType getType();
        BaseItem * item;
    protected:
        RobotType robot_type;
};

class RobotC : public Robot
{
    public:
        RobotC( int index, 
                const Position & init_pos,
                Map * map,
                Criminal * criminal
                );
        Position getNextPosition();
        int getDistance(Sherlock * sherlock);
        int getDistance(Watson * watson);
        string str();
    private:
        Criminal * criminal;
};

class RobotS : public Robot
{
    public:
        RobotS( int index, 
                const Position & init_pos,
                Map * map,
                Criminal * criminal,
                Sherlock * sherlock
                );
        Position getNextPosition();
        int getDistance();
        string str();
    private:
        Criminal * criminal;
        Sherlock * sherlock;
};

class RobotW : public Robot
{
    public:
        RobotW( int index, 
                const Position & init_pos,
                Map * map,
                Criminal * criminal,
                Watson * watson
                );
        Position getNextPosition();
        int getDistance();
        string str();
    private:
        Criminal * criminal;
        Watson * watson;
};

class RobotSW : public Robot
{
    public:
        RobotSW( int index, 
                const Position & init_pos,
                Map * map,
                Criminal * criminal,
                Sherlock * sherlock,
                Watson * watson
                );
        Position getNextPosition();
        int getDistance();
        string str();
    private:
        Criminal * criminal;
        Sherlock * sherlock;
        Watson * watson;
};

class StudyPinkProgram {
private:
    Configuration * config;
    Sherlock * sherlock;
    Watson * watson;
    Criminal * criminal;
    Map * map;
    ArrayMovingObject * arr_mv_objs;
    SherlockBag * sherlock_bag;
    WatsonBag * watson_bag;

public:
    StudyPinkProgram(const string & config_file_path);
    bool isStop() const;
    void printResult() const {
        if (sherlock->getCurrentPosition().isEqual(criminal->getCurrentPosition())) {
            cout << "Sherlock caught the criminal" << endl;
        }
        else if (watson->getCurrentPosition().isEqual(criminal->getCurrentPosition())) {
            cout << "Watson caught the criminal" << endl;
        }
        else {
            cout << "The criminal escaped" << endl;
        }
    }

    void printStep(int si) const {
        cout << "Step: " << setw(4) << setfill('0') << si
            << "--"
            << sherlock->str() << "--|--" << watson->str() << "--|--" << criminal->str() << endl;
    }

    void run(bool verbose);

    ~StudyPinkProgram();

    friend class TestStudyInPink;
};


class BaseItem
{
    public:
        BaseItem(ItemType type);
        ~BaseItem();
        virtual bool canUse(Character * obj,
                        Robot * robot) = 0;
        virtual void use(Character * const &obj,
                    Robot * robot);
    protected:
        ItemType type;
};

class MagicBook : public BaseItem
{
    public:
        MagicBook();
        bool canUse(Character * obj,
                    Robot * robot);
        void use(Character * const &obj,
                    Robot * robot);
};
class EnergyDrink : public BaseItem
{
    public:
        EnergyDrink();
        bool canUse(Character * obj,
                    Robot * robot) ;
        void use(Character * const &obj,
                    Robot * robot) ;
};

class FirstAid : public BaseItem
{
    public:
        FirstAid();
        bool canUse(Character * obj,
                    Robot * robot) ;
        void use(Character * const &obj,
                    Robot * robot) ;
};

class ExcemptionCard : public BaseItem
{
    public:
        ExcemptionCard();
        bool canUse(Character * obj,
                    Robot * robot) ;
        void use(Character * const &obj,
                    Robot * robot) ;
};

class PassingCard : public BaseItem
{
    public:
        PassingCard();
        bool canUse(Character * obj,
                    Robot * robot) ;
        void use(Character * const &obj,
                    Robot * robot) ;
    private:
        string challenge;
};

class BaseBag
{
    public:
        BaseBag();
        ~BaseBag();
        virtual bool insert (BaseItem* item); 
        virtual BaseItem* get();
        virtual BaseItem* get(ItemType itemType); 
        virtual string str() const;
    protected:
        BaseItem * item;
        BaseBag * next;
        BaseBag * head;
        BaseBag * tail;
        Character * obj;
        int num_of_current_items = 0;
};

class SherlockBag : public BaseBag
{
    public:
        SherlockBag(Sherlock * sherlock);
};

class WatsonBag : public BaseBag
{
    public:
        WatsonBag(Watson * watson);
};

#endif /* _H_STUDY_IN_PINK_2_H_ */