using System.Text;

namespace UsersMSSQL
{

    public class User
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public string SecondName { get; set; }
        public string LastName { get; set; }
        public string Phone { get; set; }
        public string Email { get; set; }
        public Account Account { get; set; }

        public override string ToString()
        {
            StringBuilder builder = new StringBuilder();
            builder.Append($"Id {Id}\n");
            builder.Append($"Name {Name}\n");
            builder.Append($"Second Name {SecondName}\n");
            builder.Append($"Last Name {LastName}\n");
            builder.Append($"Phone {Phone}\n");
            builder.Append($"Email {Email}\n");
            builder.Append($"Account {Account}");
            return builder.ToString();
        }
    }
}