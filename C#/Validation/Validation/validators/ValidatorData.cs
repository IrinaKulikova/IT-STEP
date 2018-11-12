namespace Validation
{
    public class ValidatorData : IValidatorData
    {
        readonly ISimpleValidator sValidator;
        enum LEN_PASSWORD { MIN = 6, MAX = 20 };

        public ValidatorData(ISimpleValidator sValidator)
        {
            this.sValidator = sValidator;
        }

        public bool ValidateAge(string str)
        {
            if (string.IsNullOrEmpty(str))
            {
                return false;
            }
            const int MAX_AGE_POSITION = 2;
            return sValidator.IsOnlyDigit(str) && sValidator.LessThanMaxLength(str, MAX_AGE_POSITION);
        }

        public bool ValidateMail(string str)
        {
            if (string.IsNullOrEmpty(str))
            {
                return false;
            }
            return sValidator.MatchesRegExp(str, @"^([a-z0-9_\.-]+)@([a-z0-9_\.-]+)\.([a-z\.]{2,6})$");
        }

        public bool ValidatePassword(string str)
        {
            if (string.IsNullOrEmpty(str))
            {
                return false;
            }
            return sValidator.ContainsDigit(str) && sValidator.ContainsLowwerCharacter(str) &&
                sValidator.ContainsUpperCharacter(str) && sValidator.ContainsSpecialCharacter(str) &&
                sValidator.LenBeetwen(str, (int)LEN_PASSWORD.MIN, (int)LEN_PASSWORD.MAX);
        }

        public bool ValidatePhone(string str)
        {
            if (string.IsNullOrEmpty(str))
            {
                return false;
            }
            return sValidator.MatchesRegExp(str, @"\+?\d{2}\(?\d{3}\)?\d{3}[- ]?\d{2}[- ]?\d{2}");
        }

        public bool ValidatePostIndex(string str)
        {
            if (string.IsNullOrEmpty(str))
            {
                return false;
            }
            uint countDigitInPostIndex = 5;
            return sValidator.IsOnlyDigit(str) && sValidator.LenBeetwen(str, countDigitInPostIndex, countDigitInPostIndex);
        }

        public bool ValidateUrl(string str)
        {
            if (string.IsNullOrEmpty(str))
            {
                return false;
            }
            return sValidator.MatchesRegExp(str, @"^(https?:\/\/)?([\da-z\.-]+)\.([a-z\.]{2,6})([\/\w \.-]*)*\/?$");
        }

        public bool ValidateUsername(string str)
        {
            if (string.IsNullOrEmpty(str))
            {
                return false;
            }
            return !sValidator.IsOnlyDigit(str) && !sValidator.StartsFromDigit(str);
        }
    }
}
