
        function showForm(form) {

            if (form === 'login') {
                document.getElementById('login-form').classList.remove('active');
                document.getElementById('register-form').classList.add('active');
            } else {
                document.getElementById('login-form').classList.add('active');
                document.getElementById('register-form').classList.remove('active');
            }
        }
            
        function register() {
            const username = document.getElementById('register-username').value.trim();
            const email = document.getElementById('register-email').value.trim();
            const password = document.getElementById('register-password').value.trim();
            const errorDiv = document.getElementById('register-error');

            errorDiv.textContent = ''; // Clear previous errors

            if (!username || !email || !password) {
                errorDiv.textContent = 'All fields are required!';
                return false; // Prevent form submission
            }

            if (!email.includes('@')) {
                errorDiv.textContent = 'Invalid email format!';
                return false; // Prevent form submission
            }

            const users = JSON.parse(localStorage.getItem('users')) ;
            if   (users.some(user => user.username === username)) {
                errorDiv.textContent = 'Username already exists!';
                return false; // Prevent form submission
            }

            users.push({ username, email, password });
            localStorage.setItem('users', JSON.stringify(users));
            alert('Registration successful!');
            showForm('login');
            return false; // Prevent form submission
        }

        function login() {
            const username = document.getElementById('login-username').value.trim();
            const password = document.getElementById('login-password').value.trim();
            const errorDiv = document.getElementById('login-error');

            errorDiv.textContent = ''; // Clear previous errors

            if (!username || !password) {
                errorDiv.textContent = 'All fields are required!';
                return false; // Prevent form submission
            }
                                                                
            const users = JSON.parse(localStorage.getItem(' users')) ;
            const user = users.find(user => user.username === username && user.password === password);

            if (!user) {
                errorDiv.textContent = 'Invalid username or password!';
                return false; // Prevent form submission
            }

            alert('Login successful!');
            return false; // Prevent form submission
        }
