import { render, screen } from '@testing-library/react';
import RoundApp from './RoundApp';

test('renders learn react link', () => {
  render(<RoundApp />);
  const linkElement = screen.getByText(/learn react/i);
  expect(linkElement).toBeInTheDocument();
});
